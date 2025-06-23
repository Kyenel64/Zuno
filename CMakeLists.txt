cmake_minimum_required (VERSION 3.28)

project (Zuno)

set (CoreFiles "src/Engine.h" "src/Engine.cpp" "src/BaseGame.h" "src/BaseGame.cpp"
        src/Window.cpp
        src/Window.h
        src/Graphics/Graphics.cpp
        src/Graphics/Graphics.h
        src/Key.h
        src/Graphics/Texture.h)

add_library (${PROJECT_NAME}
        ${CoreFiles})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL EXCLUDE_FROM_ALL)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL_image EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL_image/include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)

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

project (TestMain)

set (CoreFiles
        main.cpp)

add_executable(TestMain ${CoreFiles})

set_property(TARGET TestMain PROPERTY CXX_STANDARD 20)

target_include_directories(TestMain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(TestMain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Zuno/src)
target_link_libraries(TestMain PRIVATE Zuno)
