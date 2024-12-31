cmake_minimum_required(VERSION 3.29)
project(route_opt)

set(CMAKE_CXX_STANDARD 20)

add_executable(route_opt src/main.cpp src/graph.cpp src/visual.cpp src/actionHandler.cpp src/dijkstra.cpp)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(route_opt sfml-system sfml-window sfml-graphics sfml-audio sfml-network)