cmake_minimum_required(VERSION 3.22)
project(lab4_bmp_graph_generator)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES
        src/graph/algo/FruchtermanReingold.cpp
        src/graph/Graph.cpp
        src/image/BMP.cpp
        src/math/structures.cpp
        src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
