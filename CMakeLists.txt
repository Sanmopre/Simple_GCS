cmake_minimum_required(VERSION 3.10)
# set the vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "/home/sanmopre/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(GCS)

# Set the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
set(OpenGL_GL_PREFERENCE GLVND)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Add the executable
add_executable(GCS ${SOURCES})

target_link_libraries(GCS PRIVATE glfw)
target_link_libraries(GCS PRIVATE imgui::imgui)
target_link_libraries(GCS PRIVATE OpenGL::GL)
target_link_libraries(GCS PRIVATE Boost::boost)
target_link_libraries(GCS PRIVATE nlohmann_json::nlohmann_json)