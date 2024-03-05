#ifndef MAP_H
#define MAP_H

#include <vector>
#include "imageLoader.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#define MAP_GRID_STEP 32.0f
#define GRID_COLOR IM_COL32(200, 200, 200, 40)

ImVector<ImVec2> updatePlanePositions(const ImVector<ImVec2>& planePoints, const ImVec2& mapOrigin)
{
    ImVector<ImVec2> newPlanePoints;
    for(int i = 0; i < planePoints.size(); i++)
    {
        newPlanePoints.push_back(ImVec2(planePoints[i].x + mapOrigin.x, planePoints[i].y + mapOrigin.y));
    }
    return newPlanePoints;
}


void DrawMap(ImVector<ImVec2>& planePoints, Image map_image, Image plane_icon, Image gcs_icon, ImVec2 gcs_map_position, float gcs_range)
{

    //Map
    ImGui::Begin("MAP", nullptr, IMGUI_WINDOW_FLAGS);

    static ImVec2 scrolling(0.0f, 0.0f);
    static ImVec2 image_size(config_parser->map_width, config_parser->map_height);
    static ImVec2 max_scroll(-image_size.x, -image_size.y);
    static bool opt_enable_context_menu = false;

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

    //Adjust points to origin of map
    ImVector<ImVec2> points = updatePlanePositions(planePoints, origin);

    if(is_hovered)
    {
        ImGui::BeginTooltip();
        ImGui::Text("X: %f", mouse_pos_in_canvas.x);
        ImGui::Text("Y: %f", mouse_pos_in_canvas.y);
        ImGui::EndTooltip();
    }

    const float mouse_threshold_for_pan = opt_enable_context_menu ? -1.0f : 0.0f;
    if (is_active && ImGui::IsMouseDragging(ImGuiMouseButton_Right, mouse_threshold_for_pan))
    {
        scrolling.x += io.MouseDelta.x;
        scrolling.y += io.MouseDelta.y;
    }

    if(scrolling.x < max_scroll.x + canvas_sz.x)
        scrolling.x = max_scroll.x + canvas_sz.x;

    if(scrolling.y < max_scroll.y + canvas_sz.y)
        scrolling.y = max_scroll.y + canvas_sz.y;

    if(scrolling.x > 0.0f)
        scrolling.x = 0.0f;

    if(scrolling.y > 0.0f)
        scrolling.y = 0.0f;

    // Draw map in the background
    draw_list->AddImage((void*)(intptr_t)map_image.texture, ImVec2(origin.x, origin.y), ImVec2(origin.x + image_size.x, origin.y + image_size.y));
    draw_list->PushClipRect(canvas_p0, canvas_p1, true);


    // Draw grid
    for (float x = fmodf(scrolling.x, MAP_GRID_STEP); x < canvas_sz.x; x += MAP_GRID_STEP)
        draw_list->AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), GRID_COLOR);
    for (float y = fmodf(scrolling.y, MAP_GRID_STEP); y < canvas_sz.y; y += MAP_GRID_STEP)
        draw_list->AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), GRID_COLOR);



    //GCS Area and icon
    draw_list->AddCircleFilled(ImVec2(origin.x + gcs_map_position.x, origin.y + gcs_map_position.y), gcs_range, IM_COL32(20, 200, 0, 100));
    draw_list->AddImage((void*)(intptr_t)gcs_icon.texture, ImVec2(origin.x + gcs_map_position.x - config_parser->icon_size_x/2.0f, origin.y + gcs_map_position.y - config_parser->icon_size_y/2.0f), ImVec2(origin.x + gcs_map_position.x + config_parser->icon_size_x/2.0f, origin.y + gcs_map_position.y + config_parser->icon_size_y/2.0f));

    //Draw the plane path
    draw_list->AddPolyline(points.Data, points.Size, IM_COL32(255, 255, 0, 255), false, 2.5f);


    //Plane Icon
    draw_list->AddImage((void*)(intptr_t)plane_icon.texture, ImVec2((-config_parser->icon_size_x/2.0f) + points[points.size() - 1].x,(-config_parser->icon_size_y/2.0f) + points[points.size() - 1].y), ImVec2(config_parser->icon_size_x/2.0f + points[points.size() - 1].x, config_parser->icon_size_y/2.0f + points[points.size() - 1].y));

    draw_list->PopClipRect();
    ImGui::End();
}

#endif // MAP_H