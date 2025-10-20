cmake_minimum_required(VERSION 3.28)

project(ZunoTest CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY "https://github.com/google/googletest"
        GIT_TAG "52eb8108c5bdec04579160ae17225d66034bd723"
)
FetchContent_MakeAvailable(googletest)

set(SOURCES
        test_log.cpp
)

# Files to not test on CI
if (NOT DEFINED ENV{GITHUB_ACTIONS})
    list(APPEND SOURCES
            test_window.cpp
    )
endif()
add_executable(ZunoTest ${SOURCES})
target_link_libraries(ZunoTest PRIVATE ZunoEngine GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ZunoTest)
