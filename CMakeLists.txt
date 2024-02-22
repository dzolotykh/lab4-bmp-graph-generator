cmake_minimum_required(VERSION 3.26)
project(lab4_bmp_graph_generator)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4_bmp_graph_generator src/main.cpp
        src/graph/algo/FruchtermanReingold.h
        src/graph/algo/FruchtermanReingold.cpp
        src/graph/Graph.h
        src/math/Point2D.h
        src/graph/Graph.cpp
        src/image/BMP.h
        src/image/BMP.cpp
        src/math/Vector2D.h
        src/math/Vector2D.h
        src/math/Point2D.cpp
        src/math/Vector2D.cpp
        src/image/DigitsDrawer.h
)
