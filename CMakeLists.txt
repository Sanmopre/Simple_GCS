cmake_minimum_required(VERSION 3.10)
# set the vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "/home/sanmopre/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(GCS)
#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*,-llvmlibc-callee-namespace")

# Set the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
set(OpenGL_GL_PREFERENCE GLVND)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(OpenCV REQUIRED)

# Add Protocol Buffers
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/imgui)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS 
    assets/proto_files/gcs_data.proto
    assets/proto_files/drone_data.proto
)
list(APPEND SOURCES ${PROTO_SRCS} ${PROTO_HDRS})
# Add the executable
add_executable(GCS ${SOURCES})

target_link_libraries(GCS PRIVATE glfw)
target_link_libraries(GCS PRIVATE imgui::imgui)
target_link_libraries(GCS PRIVATE OpenGL::GL)
target_link_libraries(GCS PRIVATE Boost::boost)
target_link_libraries(GCS PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(GCS PRIVATE ${PROTOBUF_LIBRARIES})
target_link_libraries(GCS PRIVATE ${OpenCV_LIBS})

include(InstallRequiredSystemLibraries)
install(TARGETS GCS DESTINATION bin)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_CONTACT "Santiago Moliner <moliner.santiago@gmail.com>")
include(CPack)