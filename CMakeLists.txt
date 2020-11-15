cmake_minimum_required(VERSION 3.17)
set(TARGET_NAME stanford_algorithms)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "src/*.cpp")
add_executable (stanford_algorithms ${SOURCES})

project (${TARGET_NAME})

target_include_directories(${TARGET_NAME} PRIVATE include)