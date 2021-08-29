cmake_minimum_required(VERSION 3.17)
project(sequence)

set(CMAKE_CXX_STANDARD 14)

add_executable(sequence main.cpp dynamic-array.h dynamic-array.cpp)