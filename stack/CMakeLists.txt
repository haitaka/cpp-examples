cmake_minimum_required(VERSION 3.17)
project(stack)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack src/main.cpp src/stack.cpp src/stack.h src/list.cpp src/list.h src/list-stack.cpp src/list-stack.h src/array-stack.cpp src/array-stack.h)

