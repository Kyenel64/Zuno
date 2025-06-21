cmake_minimum_required (VERSION 3.28)

project ("Zuno")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ZunoEditor)

# Variables
set(ZUNO_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Zuno)

# Include sub-projects.
add_subdirectory("Zuno")
