cmake_minimum_required(VERSION 3.19)
project(lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab
        Car.cpp
        Car.h
        Collection.h
        Employee.cpp
        Employee.h
        main.cpp
        ReadWrite.cpp
        ReadWrite.h
        searchNlist.h
        Student.cpp
        Student.h)
