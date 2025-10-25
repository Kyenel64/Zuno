cmake_minimum_required(VERSION 3.28)

project(ZunoTest CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY "https://github.com/google/googletest"
        GIT_TAG "v1.17.0"
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SOURCES
        test_log.cpp
        test_window.cpp
        test_scripting.cpp
)

# Files to not test on CI
if (DEFINED ENV{GITHUB_ACTIONS})
    list(REMOVE_ITEM SOURCES
            test_window.cpp
    )
endif()
add_executable(ZunoTest ${SOURCES})
target_link_libraries(ZunoTest PRIVATE ZunoEngine GTest::gtest_main)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.lua ${CMAKE_CURRENT_BINARY_DIR}/test.lua COPYONLY)

include(GoogleTest)
add_test(NAME ZunoTests COMMAND ZunoTest)
