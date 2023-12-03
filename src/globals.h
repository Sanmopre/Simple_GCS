#pragma once


#ifdef NO_MOVE
    #define IMGUI_WINDOW_FLAGS ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
#else
    #define IMGUI_WINDOW_FLAGS ImGuiWindowFlags_None
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}
