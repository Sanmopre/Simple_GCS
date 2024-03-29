#pragma once

#define NO_MOVE

#ifdef NO_MOVE
    #define IMGUI_WINDOW_FLAGS ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
#else
    #define IMGUI_WINDOW_FLAGS ImGuiWindowFlags_None
#endif

#define HISTOGRAM_SIZE 720

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}
