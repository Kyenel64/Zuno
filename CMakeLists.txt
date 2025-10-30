cmake_minimum_required(VERSION 3.28)

project(Zuno C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(deps.cmake)

add_library(ZunoEngine STATIC
        src/core/Log.h
        src/core/Log.cpp
        src/modules/window/Window.h
        src/modules/window/Window.cpp
        src/modules/event/Event.h
        src/modules/input/Key.h
        src/modules/input/MouseButton.h
        src/modules/scripting/ScriptEngine.h
        src/modules/scripting/ScriptEngine.cpp
        src/modules/scene/Scene.h
        src/modules/scene/Scene.cpp
        src/modules/scene/Entity.h
)
target_include_directories(ZunoEngine PUBLIC src/ include/)
target_link_libraries(ZunoEngine PRIVATE glfw PUBLIC spdlog sol2 lua_static EnTT::EnTT)

if (APPLE)
    add_compile_definitions(ZUNO_APPLE)
elseif (WIN32)
    add_compile_definitions(ZUNO_WINDOWS)
elseif (UNIX)
    add_compile_definitions(ZUNO_LINUX)
endif()

add_compile_definitions($<$<CONFIG:Debug>:ZUNO_DEBUG>)
add_compile_definitions($<$<CONFIG:Release>:ZUNO_RELEASE>)

target_precompile_headers(ZunoEngine PUBLIC src/core/ZunoPCH.h)

# Zuno exe
add_executable(Zuno
        src/main.cpp
        src/Engine.h
        src/Engine.cpp
)
target_include_directories(Zuno PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(Zuno PRIVATE ZunoEngine)

# Tests
option(ZUNO_BUILD_TESTS "Build zuno test" ON)
if (ZUNO_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
