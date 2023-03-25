cmake_minimum_required(VERSION 3.19)
project(ws05_diy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ws05_diy
        Mark.cpp
        Mark.h
        markMain.cpp)
