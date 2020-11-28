cmake_minimum_required(VERSION 3.17)

project (stanford_algorithms)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

add_executable (scc ${SOURCES} assignments/scc.cpp)
target_include_directories(scc PRIVATE include)

add_executable (dijkstra ${SOURCES} assignments/dijkstra.cpp)
target_include_directories(dijkstra PRIVATE include)

add_executable (inversions ${SOURCES} assignments/inversions.cpp)
target_include_directories(inversions PRIVATE include)

add_executable (median ${SOURCES} assignments/median.cpp)
target_include_directories(median PRIVATE include)
