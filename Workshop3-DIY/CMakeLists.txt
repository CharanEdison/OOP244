cmake_minimum_required(VERSION 3.19)
project(Workshop3_DIY)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Workshop3_DIY
        calListTester.cpp
        CalorieList.cpp
        CalorieList.h
        cstring.cpp
        cstring.h
        Food.cpp
        Food.h)
