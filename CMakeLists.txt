cmake_minimum_required(VERSION 3.6)
project(state_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES state.c state.h main.c power_state.c power_state.h led.c led.h system_status.c system_status.h)
add_executable(state_test ${SOURCE_FILES})