cmake_minimum_required(VERSION 3.10)
# Project name
project(power)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories (recursive for headers)
include_directories(cli/inc)
include_directories(cli/inc/factory)
include_directories(cli/inc/observer)
include_directories(controller/inc)
include_directories(model/inc)
include_directories(model/inc/factory)

# Glob all source files recursively
file(GLOB_RECURSE SOURCES 
    "${CMAKE_SOURCE_DIR}/cli/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/cli/src/factory/*.cpp"
    "${CMAKE_SOURCE_DIR}/cli/src/observer/*.cpp"
    "${CMAKE_SOURCE_DIR}/controller/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/model/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/model/src/factory/*.cpp"
    "${CMAKE_SOURCE_DIR}/view/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/main.cpp"
)

# Glob all header files recursively (if needed)
file(GLOB_RECURSE HEADERS
    "${CMAKE_SOURCE_DIR}/cli/inc/*.hpp"
    "${CMAKE_SOURCE_DIR}/cli/inc/factory/*.hpp"
    "${CMAKE_SOURCE_DIR}/cli/inc/observer/*.hpp"
    "${CMAKE_SOURCE_DIR}/controller/inc/*.hpp"
    "${CMAKE_SOURCE_DIR}/model/inc/*.hpp"
    "${CMAKE_SOURCE_DIR}/model/inc/factory/*.hpp"
    "${CMAKE_SOURCE_DIR}/view/inc/*.hpp"
    "${CMAKE_SOURCE_DIR}/main.hpp"
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

