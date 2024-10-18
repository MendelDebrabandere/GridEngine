cmake_minimum_required(VERSION 3.29)
project(GridEngine)

# Set the C++ standard and compiler flags
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

# Find Vulkan and GLFW packages
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_compile_definitions(PROJECT_ROOT="${PROJECT_SOURCE_DIR}")

add_executable(GridEngine GridEngine/main.cpp
        GridEngine/Renderer/GEWindow.cpp
        GridEngine/Renderer/GEWindow.h
        GridEngine/FirstApp.cpp
        GridEngine/FirstApp.h
        GridEngine/FirstApp.cpp
        GridEngine/Renderer/GEPipeline.cpp
        GridEngine/Renderer/GEPipeline.h
        GridEngine/Renderer/GEDevice.cpp
        GridEngine/Renderer/GEDevice.h
        GridEngine/Renderer/GESwapChain.h
        GridEngine/Renderer/GESwapChain.cpp
)

add_custom_target(compile_shaders ALL
        COMMAND /bin/bash ${PROJECT_SOURCE_DIR}/GridEngine/Shaders/compile.sh
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/GridEngine/Shaders
        COMMENT "Compiling shaders"
)

# Link the Vulkan and GLFW libraries, along with other dependencies
target_link_libraries(GridEngine PRIVATE Vulkan::Vulkan glfw dl pthread X11 Xxf86vm Xrandr Xi)
