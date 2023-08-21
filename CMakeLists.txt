cmake_minimum_required(VERSION 3.25)
project(utec_aed)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

add_executable(utec_aed
        main.cpp
        include/sorting.h)
