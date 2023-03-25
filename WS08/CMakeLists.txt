cmake_minimum_required(VERSION 3.19)
project(WS08)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(lab)

add_executable(WS08
        lab/Line.cpp
        lab/Line.h
        lab/main.cpp
        lab/Rectangle.cpp
        lab/Rectangle.h
        lab/Shape.cpp
        lab/Shape.h
        LblShape.cpp
        LblShape.h)
