project ("Zuno")

set (CoreFiles "Engine.h" "Engine.cpp")

# Source files
add_library (${PROJECT_NAME}
        ${CoreFiles})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

# Dependencies

# Include Paths
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Libraries

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
