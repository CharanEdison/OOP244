cmake_minimum_required(VERSION 3.19)
project(Workshop4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Workshop4
        Canister.cpp
        Canister.h
        canisterMain.cpp
        cstring.cpp
        cstring.h)
