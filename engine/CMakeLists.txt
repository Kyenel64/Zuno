cmake_minimum_required(VERSION 3.28)

project(ZunoEngine CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(deps.cmake)

add_library(ZunoEngine STATIC
        window/Window.h
        window/Window.cpp
        event/Event.h
        input/Key.h
        input/MouseButton.h
)
target_include_directories(ZunoEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ZunoEngine PRIVATE glfw)
