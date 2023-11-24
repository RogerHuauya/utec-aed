cmake_minimum_required(VERSION 3.25)
project(utec_aed)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)


add_executable(
        treap
        src/project/treap.cpp
        include/treap.h
)

add_executable(
        red_black_tree
        src/project/red_black_tree.cpp
        include/random_generator.h
)

add_executable(
        bst
        src/project/bst.cpp
        include/random_generator.h
)
