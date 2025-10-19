cmake_minimum_required(VERSION 3.28)

project(Zuno CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(engine)

add_executable(
        Zuno
        main.cpp
)
target_include_directories(Zuno PUBLIC ${CMAKE_SOURCE_DIR}/engine)
target_link_libraries(Zuno PRIVATE ZunoEngine)

# tests
enable_testing()
add_subdirectory(tests)
