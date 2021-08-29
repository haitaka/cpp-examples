cmake_minimum_required(VERSION 3.17)
project(cas)

set(CMAKE_CXX_STANDARD 14)

add_executable(cas main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(cas Threads::Threads)
