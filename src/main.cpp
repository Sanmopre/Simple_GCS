#include <stdio.h>
#include <GLFW/glfw3.h>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include <ctime>

#include "globals.h"
#include "udp.h"
#include "config_parser.h"
#include "imageLoader.h"
#include "style.h"
#include "data.h"

#define GL_SILENCE_DEPRECATION



int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    //Config parser
    config_parser = new ConfigParser("../assets/config.json");

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(config_parser->window_width, config_parser->window_height, "GCS", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows



    ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None; //ImGuiDockNodeFlags_NoUndocking;

    if (!config_parser->resizable)
        dockspace_flags |= ImGuiDockNodeFlags_NoResize;
    

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    io.Fonts->AddFontFromFileTTF("../assets/fonts/CubicCoreMono.ttf", 15.0f);
    embraceTheDarkness();

    auto start_time = std::chrono::steady_clock::now();

    // Our state
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    std::vector<int> messages;
    messages.push_back(0);
    messages.push_back(1);
    messages.push_back(2);
    messages.push_back(6);

    float trhust_engine_1 = 0.0f;
    float trhust_engine_2 = 0.0f;

    float engine_1_temperature = 0.0f;
    float engine_2_temperature = 0.0f;

    int engine_1_rpm = 0;
    int engine_2_rpm = 0;

    bool enable_engine_1 = true;
    bool enable_engine_2 = true;

    float pitch = 0.0f;
    float roll = 0.0f;
    float yaw = 0.0f;

    int altitude = 0;
    int speed = 0;
    int vertical_speed = 0;
    int bank = 0;

    static float arr_altitude[720] = {0};

    static Flaps flaps = Flaps::LANDING;
    bool split_throttles = false;

    float plot_refresh_rate = 1.0f;
    float plot_refresh_rate_counter = 0.0f;

    Image airbus_image;
    bool ret = LoadTextureFromFile("../assets/images/AirbusLogo.png", &airbus_image);
    IM_ASSERT(ret);

    Image map_image;
    ret = LoadTextureFromFile("../assets/images/map.jpeg", &map_image);
    IM_ASSERT(ret);


    boost::asio::io_service io_service;
    UDPServer server(io_service, config_parser->uav_ip, config_parser->uav_port, config_parser->local_ip, config_parser->local_port);
    
    // Run io_service in a separate thread
    std::thread io_service_thread([&io_service]() { io_service.run(); });

    DroneData drone_data;
    GCSData gcs_data;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        auto start_loop = std::chrono::steady_clock::now();
        std::string message;
        CreateGCSData(gcs_data, message);
        server.send(message);
        std::string response = server.get_message();

        if(response.size() > 0)
            ParseDroneData(response, drone_data);
        
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), dockspace_flags);
        std::string recived_message = server.get_message();
        //bool show_demo_window = true;
        //ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::BeginMainMenuBar();  
        ImGui::Text("GCS");
        ImGui::SameLine(ImGui::GetWindowWidth() - 80); // Position the button on the right
        if (ImGui::Selectable("CLOSE", false, ImGuiSelectableFlags_None)) {
            glfwSetWindowShouldClose(window, true);
        }
        ImGui::EndMainMenuBar();


        //Thrust control
        ImGui::Begin("THRUST CONTROLL", nullptr, IMGUI_WINDOW_FLAGS);
        ImGui::Checkbox("Split the throttles", &split_throttles);
        if (split_throttles) 
        {            
            ImGui::Text("Engine 1");
            if(!enable_engine_1)
                ImGui::BeginDisabled();
            ImGui::SliderFloat("Thrust Power 1", &gcs_data.throttle_1, 0.0f, 100.0f);
            if(!enable_engine_1)
                ImGui::EndDisabled();


            ImGui::Text("Engine 2");
            if(!enable_engine_2)
                ImGui::BeginDisabled();
            ImGui::SliderFloat("Thrust Power 2", &gcs_data.throttle_2, 0.0f, 100.0f);
            if(!enable_engine_2)
                ImGui::EndDisabled();

        }
        else 
        {
            ImGui::Text("Engines");
            ImGui::SliderFloat("Thrust Power", &gcs_data.throttle_1, 0.0f, 100.0f);
            gcs_data.throttle_2 = gcs_data.throttle_1;
        }

        std::string temperature_1_string = std::to_string(drone_data.temperature_engine_1);
        std::string temperature_2_string = std::to_string(drone_data.temperature_engine_2);
        temperature_1_string.append(" C");
        temperature_2_string.append(" C");

        ImGui::Text("Engine 1 Temperature: ");
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", temperature_1_string.c_str());

        ImGui::Text("Engine 2 Temperature: ");
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", temperature_2_string.c_str());

        std::string rpm_1_string = std::to_string(drone_data.rpm_engine_1);
        std::string rpm_2_string = std::to_string(drone_data.rpm_engine_2);

        ImGui::Text("Engine 1 RPM: ");
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 1, 1), "%s", rpm_1_string.c_str());

        ImGui::Text("Engine 2 RPM: ");
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 1, 1), "%s", rpm_2_string.c_str());

        ImGui::Checkbox("Enable Engine 1", &enable_engine_1);
        ImGui::SameLine();
        ImGui::Checkbox("Enable Engine 2", &enable_engine_2);
        ImGui::End();



        ImGui::Begin("LOGO", nullptr, IMGUI_WINDOW_FLAGS);
        ImGui::Image((void*)(intptr_t)airbus_image.texture, ImVec2(airbus_image.width / 10, airbus_image.height/ 10));
        ImGui::End();


        ImGui::Begin("STABILIZER CONTROL", nullptr, IMGUI_WINDOW_FLAGS);
        ImGui::SliderFloat("Pitch", &gcs_data.pitch, -90.0f, 90.0f);
        ImGui::SliderFloat("Roll", &gcs_data.roll, -90.0f, 90.0f);
        ImGui::SliderFloat("Yaw", &gcs_data.yaw, -90.0f, 90.0f);
        ImGui::End();


        //Flaps control
        ImGui::Begin("FLAPS CONTROL", nullptr, IMGUI_WINDOW_FLAGS);
        ImGui::RadioButton("LANDING", reinterpret_cast<int*>(&flaps), static_cast<int>(Flaps::LANDING)); ImGui::SameLine();
        ImGui::RadioButton("TAKEOFF", reinterpret_cast<int*>(&flaps), static_cast<int>(Flaps::TAKEOFF)); ImGui::SameLine();
        ImGui::RadioButton("CRUISE", reinterpret_cast<int*>(&flaps), static_cast<int>(Flaps::CRUISE));
        ImGui::End();


            //Map
            ImGui::Begin("MAP", nullptr, IMGUI_WINDOW_FLAGS);
            static ImVector<ImVec2> points;
            static ImVec2 scrolling(0.0f, 0.0f);
            static bool opt_enable_context_menu = false;
            const float GRID_STEP = 32.0f;

            ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();      // ImDrawList API uses screen coordinates!
            ImVec2 canvas_sz = ImGui::GetContentRegionAvail();   // Resize canvas to what's available
            if (canvas_sz.x < 50.0f) canvas_sz.x = 50.0f;
            if (canvas_sz.y < 50.0f) canvas_sz.y = 50.0f;
            ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

            // Draw border and background color
            ImGuiIO& io = ImGui::GetIO();
            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
            draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

            // This will catch our interactions
            ImGui::InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
            const bool is_hovered = ImGui::IsItemHovered(); // Hovered
            const bool is_active = ImGui::IsItemActive();   // Held
            const ImVec2 origin(canvas_p0.x + scrolling.x, canvas_p0.y + scrolling.y); // Lock scrolled origin
            const ImVec2 mouse_pos_in_canvas(io.MousePos.x - origin.x, io.MousePos.y - origin.y);

            //testing drawing
            /*
            points.push_back({0.0f, 0.0f});
            points.push_back({100.0f, 100.0f});

            points.push_back({ 100.0f, 100.0f });
            points.push_back({ 200.0f, 100.0f });

            points.push_back({ 200.0f, 100.0f });
            points.push_back({ 200.0f, 200.0f });

            points.push_back({ 200.0f, 200.0f });
            points.push_back({ 100.0f, 200.0f });
            */


            if(is_hovered)
            {
                ImGui::BeginTooltip();
                ImGui::Text("Latitute: %f", mouse_pos_in_canvas.x);
                ImGui::Text("Longitute: %f", mouse_pos_in_canvas.y);
                ImGui::EndTooltip();
            }

            const float mouse_threshold_for_pan = opt_enable_context_menu ? -1.0f : 0.0f;
            if (is_active && ImGui::IsMouseDragging(ImGuiMouseButton_Right, mouse_threshold_for_pan))
            {
                scrolling.x += io.MouseDelta.x;
                scrolling.y += io.MouseDelta.y;
            }

            draw_list->AddImage((void*)(intptr_t)map_image.texture, ImVec2(origin.x, origin.y), ImVec2(origin.x + 2000, origin.y + 2000));
            // Draw grid + all lines in the canvas
            draw_list->PushClipRect(canvas_p0, canvas_p1, true);


            for (float x = fmodf(scrolling.x, GRID_STEP); x < canvas_sz.x; x += GRID_STEP)
                draw_list->AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), IM_COL32(200, 200, 200, 40));
            for (float y = fmodf(scrolling.y, GRID_STEP); y < canvas_sz.y; y += GRID_STEP)
                draw_list->AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), IM_COL32(200, 200, 200, 40));
            
            for (int n = 0; n < points.Size; n += 2)
                draw_list->AddLine(ImVec2(origin.x + points[n].x, origin.y + points[n].y), ImVec2(origin.x + points[n + 1].x, origin.y + points[n + 1].y), IM_COL32(255, 255, 0, 255), 2.0f);
        
            draw_list->PopClipRect();
            ImGui::End();

            ImGui::Begin("DRONE POSITION", nullptr, IMGUI_WINDOW_FLAGS);
            ImGui::Dummy(ImVec2(0,1));
            ImGui::TextColored(ImVec4(0, 1, 0, 1), "UAV CONNECTED");
            ImGui::Dummy(ImVec2(0,5));
            ImGui::Text("Latitute: %f", drone_data.latitude);
            ImGui::SameLine();
            ImGui::Text("Speed: %f", drone_data.speed);
            ImGui::Text("Longitute: %f", drone_data.longitude);
            ImGui::SameLine();
            ImGui::Text("Vertical Speed: %f", drone_data.vertical_speed);
            ImGui::Text("Altitude: %d", drone_data.altitude);
            ImGui::Text("Fuel: %f", drone_data.fuel);
            ImGui::End();
    
            ImGui::Begin("MESSAGE LOG", nullptr, IMGUI_WINDOW_FLAGS);

            for(auto message : messages)
            {
                ImVec4 color = ImVec4(1, 1, 1, 1);
                if(message  > 5)
                {
                    color = ImVec4(0.9, 0.8, 0, 1);
                }
                else
                {
                    color = ImVec4(1, 0, 0, 1);
                }
                ImVec2 textSize = ImGui::CalcTextSize(uav_messages_map[message].c_str());
                ImVec2 cursorPos = ImGui::GetCursorScreenPos();
                if(plot_refresh_rate_counter > plot_refresh_rate/2.0f)
                    ImGui::GetWindowDrawList()->AddRectFilled(cursorPos, ImVec2(cursorPos.x + textSize.x, cursorPos.y + textSize.y), ImGui::ColorConvertFloat4ToU32(color));
                
                ImGui::TextUnformatted(uav_messages_map[message].c_str());
            }
            ImGui::End();

            ImGui::Begin("TARGETS", nullptr, IMGUI_WINDOW_FLAGS);
        
            ImGui::PushStyleVar(ImGuiStyleVar_GrabMinSize, 40);
            ImGui::VSliderInt("##v/s", ImVec2(50, 145), &gcs_data.target_vertical_speed, -500, 500, "%d\nv/s");
            ImGui::SameLine();
            ImGui::VSliderInt("##alt", ImVec2(50, 145), &gcs_data.target_altitude, 0, 10000, "%d\nalt");
            ImGui::SameLine();
            ImGui::VSliderInt("##spd", ImVec2(50, 145), &gcs_data.target_speed, -0, 1500, "%d\nspd");
            ImGui::SameLine();
            ImGui::VSliderInt("##bnk", ImVec2(50, 145), &gcs_data.target_bank, -90, 90, "%d\nbnk");
            ImGui::SameLine();
            ImGui::Dummy(ImVec2(50.0f, 0.0f));
            ImGui::SameLine();
            ImGui::Button("SEND", ImVec2(50, 145));
            ImGui::PopStyleVar();
            ImGui::End();

            if(plot_refresh_rate_counter >= plot_refresh_rate){
                shift_and_add(arr_altitude, 720, (float)drone_data.altitude);
                plot_refresh_rate_counter = 0;
            }
            

            ImGui::Begin("PLOTS", nullptr, IMGUI_WINDOW_FLAGS);
            ImGui::PlotLines("Altitude", arr_altitude, IM_ARRAYSIZE(arr_altitude));
            // Get the current time
            auto now = std::chrono::system_clock::now();
            auto now_steady = std::chrono::steady_clock::now();
            std::time_t now_c = std::chrono::system_clock::to_time_t(now);
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now_steady - start_time);

            char date_str[30];
            char time_str[30];
            std::strftime(date_str, sizeof(date_str), "%Y-%m-%d", std::localtime(&now_c));
            std::strftime(time_str, sizeof(time_str), "%H:%M:%S", std::localtime(&now_c));

            ImGui::Text("Date: %s", date_str);
            ImGui::SameLine();
            ImGui::Text("Time: %s", time_str);

            int elapsed_hours = elapsed.count() / 3600;
            int elapsed_minutes = (elapsed.count() % 3600) / 60;
            int elapsed_seconds = elapsed.count() % 60;
            ImGui::Text("Time since startup: %02d:%02d:%02d", elapsed_hours, elapsed_minutes, elapsed_seconds);

            ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

 
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }


        glfwSwapBuffers(window);
        auto end_loop = std::chrono::steady_clock::now();
        auto elapsed_loop = std::chrono::duration_cast<std::chrono::milliseconds>(end_loop - start_loop);
        plot_refresh_rate_counter += elapsed_loop.count()/1000.0f;
    }
        // Wait for the io_service thread to finish
    //io_service_thread.join();
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
