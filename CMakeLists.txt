cmake_minimum_required(VERSION 3.28)

project(Zuno CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(deps.cmake)

add_executable(
        Zuno
        src/main.cpp
        src/Engine/Window.h
        src/Engine/Window.cpp
        src/Engine/Event.h
)

target_link_libraries(Zuno PRIVATE glfw)
