# FILEPATH: /home/sanmopre/gcs/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE "/home/sanmopre/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(MyProject)

# Set the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")


find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

# Add the executable
add_executable(MyProject ${SOURCES})

target_link_libraries(MyProject PRIVATE glfw)
target_link_libraries(MyProject PRIVATE imgui::imgui)
target_link_libraries(MyProject PRIVATE OpenGL::GL)