#include <stdio.h>
#include <GLFW/glfw3.h>

#include "globals.h"
#include "udp.h"
#include "config_parser.h"
#include "imageLoader.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#define GL_SILENCE_DEPRECATION


int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;


    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "GCS", nullptr, nullptr);
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


    //Config parser
    config_parser = new ConfigParser("../assets/config.json");


    ImGui::StyleColorsDark();


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

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    float trhust_engine_1 = 0.0f;
    float trhust_engine_2 = 0.0f;


    Image airbus_image;
    bool ret = LoadTextureFromFile("../assets/images/AirbusLogo.png", &airbus_image);
    IM_ASSERT(ret);

    Image map_image;
    ret = LoadTextureFromFile("../assets/images/map.jpeg", &map_image);
    IM_ASSERT(ret);

    UDPServer udp_server;
    udp_server.Connect(config_parser->ip, config_parser->port);


    while (!glfwWindowShouldClose(window))
    {

        glfwPollEvents();
        //SendUDPMessage(std::to_string(trhust_engine_1), config_parser->ip, config_parser->port);
        udp_server.Send(std::to_string(trhust_engine_1));
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        
        ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::BeginMainMenuBar();  
        ImGui::Text("GCS");
        ImGui::SameLine(ImGui::GetWindowWidth() - 80); // Position the button on the right
        if (ImGui::Selectable("CLOSE", false, ImGuiSelectableFlags_None)) {
            glfwSetWindowShouldClose(window, true);
        }
        ImGui::EndMainMenuBar();


        ImGui::Begin("THRUST CONTROLL", nullptr, IMGUI_WINDOW_FLAGS);
        ImGui::Text("Engine 1");
        ImGui::SliderFloat("Thrust 1", &trhust_engine_1, 0.0f, 100.0f);
        ImGui::Text("Engine 2");
        ImGui::SliderFloat("Thrust 2", &trhust_engine_2, 0.0f, 100.0f);
        ImGui::End();

        ImGui::Begin("LOGO", nullptr, IMGUI_WINDOW_FLAGS);
        ImGui::Image((void*)(intptr_t)airbus_image.texture, ImVec2(airbus_image.width / 10, airbus_image.height/ 10));
        ImGui::End();

        ImGui::Begin("MAP", nullptr, IMGUI_WINDOW_FLAGS);
        ImGui::Image((void*)(intptr_t)map_image.texture, ImVec2(map_image.width / 4, map_image.height / 4));
        if (ImGui::IsItemHovered())
        {
            ImVec2 mouse_pos = ImGui::GetMousePos();
            ImVec2 item_pos = ImGui::GetItemRectMin();
            ImVec2 local_pos = ImVec2(mouse_pos.x - item_pos.x, mouse_pos.y - item_pos.y);
            ImGui::BeginTooltip();
            ImGui::Text("Pixel position: (%.1f,%.1f)", local_pos.x, local_pos.y);
            ImGui::EndTooltip();
        }
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
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
