cmake_minimum_required(VERSION 3.6)
project(binaryHeap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinaryHeap.h BinaryHeap.cpp)
add_executable(binaryHeap ${SOURCE_FILES})