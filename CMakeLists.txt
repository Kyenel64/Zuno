cmake_minimum_required (VERSION 3.28)

project (Zuno)

set (CoreFiles "src/Engine.h" "src/Engine.cpp" "src/BaseGame.h" "src/BaseGame.cpp"
        src/Run.h
        src/Window.cpp
        src/Window.h)

add_library (${PROJECT_NAME}
        ${CoreFiles})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL/include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

# Defines
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Debug>:ZUNO_DEBUG>)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Release>:ZUNO_RELEASE>)
IF (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ZUNO_WINDOWS)
ELSEIF (APPLE)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ZUNO_APPLE)
ELSEIF (LINUX)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ZUNO_LINUX)
ENDIF()
