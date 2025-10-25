include(FetchContent)

# GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY "https://github.com/glfw/glfw"
        GIT_TAG "7b6aead9fb88b3623e3b3725ebb42670cbe4c579" # v3.4
)
FetchContent_MakeAvailable(glfw)

# spdlog
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
        GIT_TAG "486b55554f11c9cccc913e11a87085b2a91f706f" # v1.16
)
FetchContent_MakeAvailable(spdlog)

# sol2
FetchContent_Declare(
        sol2
        GIT_REPOSITORY "https://github.com/ThePhD/sol2.git"
        GIT_TAG "v3.5.0"
)
FetchContent_MakeAvailable(sol2)

# lua_static
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
        ${lua_SOURCE_DIR}/onelua.c
)
add_library(lua_static STATIC ${LUA_SRC})
target_include_directories(lua_static PUBLIC ${lua_SOURCE_DIR})
