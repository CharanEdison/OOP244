cmake_minimum_required(VERSION 3.19)
project(lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab
        cstring.cpp
        cstring.h
        TextFile.cpp
        TextFile.h
        w6p1_tester.cpp)
