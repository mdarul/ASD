cmake_minimum_required(VERSION 3.7)
project(sortings)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp list.cpp list.h Table.cpp Table.h utils.cpp utils.h)
add_executable(sortings ${SOURCE_FILES})