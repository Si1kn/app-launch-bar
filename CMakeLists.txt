cmake_minimum_required(VERSION 3.22)
project("hello")

set(CMAKE_CXX_STANDARD 14)

# Must set the path to the main.cpp, for example: scripts/main.cpp if it is inside a folder
add_executable(${PROJECT_NAME} "scripts/engine/Window.cpp" "scripts/engine/Window.h" scripts/game/Manager.cpp "scripts/engine/renderer/Renderer.cpp" "scripts/engine/renderer/Renderer.h" "scripts/engine/renderer/Colour.h" scripts/util/stb_image.h scripts/util/ImageReader.h scripts/util/ImageReader.cpp
        scripts/engine/renderer/fonts/FontRenderer.cpp
        scripts/engine/renderer/fonts/FontRenderer.h)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
target_compile_options(${PROJECT_NAME} PRIVATE -mavx)