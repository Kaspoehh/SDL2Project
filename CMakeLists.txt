cmake_minimum_required(VERSION 3.21)
project(SDL2Project)

set(CMAKE_CXX_STANDARD 14)
set(SDL_INCLUDE_DIR D:/Packages/SDL2/include)
set(SDL_IMAGE_INCLUDE_DIR D:/Packages/SDL2Image/include)

set(SDL_LIB_DIR D:/Packages/SDL2/lib/x86)
set(SDL_IMAGE_LIB_DIR D:/Packages/SDL2Image/lib/x86)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDL_IMAGE_INCLUDE_DIR})

link_directories(${SDL_LIB_DIR})
link_directories(${SDL_IMAGE_LIB_DIR})

add_executable(SDL2Project main.cpp Game.cpp Game.h)

target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image)