cmake_minimum_required(VERSION 3.10)
project(cli_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Define directories for source and header files
set(SRC_DIR ../src)
set(INC_DIR ../inc)

# Include directories
include_directories(${INC_DIR} ${INC_DIR}/factory)

# Source files from the cli project
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp)

# Test files (specific to the test folder)
set(TEST_FILES main.cpp)

# Output directories for build artifacts
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Add the test executable
add_executable(${PROJECT_NAME} ${SRC_FILES} ${TEST_FILES})

