cmake_minimum_required(VERSION 3.17)
project(threads)

set(CMAKE_CXX_STANDARD 14)

add_executable(threads main.cpp queue.cpp queue.h)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(threads Threads::Threads)
