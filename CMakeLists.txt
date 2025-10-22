cmake_minimum_required(VERSION 3.28)

project(Zuno C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/engine)

### Deps
include(FetchContent)
FetchContent_Declare(
        sol2
        GIT_REPOSITORY "https://github.com/ThePhD/sol2.git"
        GIT_TAG "v3.5.0"
)
FetchContent_MakeAvailable(sol2)

# Lua
FetchContent_Declare(
        lua
        GIT_REPOSITORY "https://github.com/lua/lua.git"
        GIT_TAG "v5.4.8"
)
FetchContent_MakeAvailable(lua)
file(GLOB LUA_SRC
        ${lua_SOURCE_DIR}/*.c
)
list(REMOVE_ITEM LUA_SRC
        ${lua_SOURCE_DIR}/luac.c
        ${lua_SOURCE_DIR}/lua.c
)
add_library(lua_static STATIC ${LUA_SRC})
target_include_directories(lua_static PUBLIC ${lua_SOURCE_DIR})

# Zuno exe
add_executable(Zuno
        src/main.cpp
        src/scripting/ScriptEngine.cpp
        src/scripting/ScriptEngine.h
)
target_include_directories(Zuno PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(Zuno PRIVATE ZunoEngine sol2 lua_static)

