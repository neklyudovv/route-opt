cmake_minimum_required(VERSION 3.29)
project(route_opt)

set(CMAKE_CXX_STANDARD 20)

add_executable(route_opt src/main.cpp src/graph.cpp)
