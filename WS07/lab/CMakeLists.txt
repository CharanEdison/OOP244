cmake_minimum_required(VERSION 3.19)
project(lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab
        main.cpp
        MotorVehicle.cpp
        MotorVehicle.h
        cstring.cpp
        cstring.h
        Truck.cpp
        Truck.h)
