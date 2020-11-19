cmake_minimum_required(VERSION 3.17)

project (stanford_algorithms)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

add_executable (scc ${SOURCES} assignments/scc.cpp)
target_include_directories(scc PRIVATE include)
