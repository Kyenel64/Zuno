include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY "https://github.com/glfw/glfw"
        GIT_TAG "7b6aead9fb88b3623e3b3725ebb42670cbe4c579" # v3.4
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
        GIT_TAG "486b55554f11c9cccc913e11a87085b2a91f706f" # v1.16
)
FetchContent_MakeAvailable(spdlog)
