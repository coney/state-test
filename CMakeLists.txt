cmake_minimum_required(VERSION 3.6)
project(state_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(state_test ${SOURCE_FILES})