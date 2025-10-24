cmake_minimum_required(VERSION 3.28)

project(Zuno C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(engine)

# Zuno exe
add_executable(Zuno
        src/main.cpp
        src/ZunoApp.h
        src/ZunoApp.cpp
)
target_include_directories(Zuno PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(Zuno PRIVATE ZunoEngine)

