cmake_minimum_required(VERSION 3.6)
project(state_test)

include_directories(gmock src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES src/state.c src/state.h main.c src/power_state.c src/power_state.h src/led.c src/led.h src/system_status.c src/system_status.h test/state_test.cpp)
add_executable(state_test ${SOURCE_FILES})