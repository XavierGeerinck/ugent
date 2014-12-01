cmake_minimum_required(VERSION 2.8.4)
project(Reeks_8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic")

set(SOURCE_FILES oef117.cpp)
add_executable(Reeks_8 ${SOURCE_FILES})