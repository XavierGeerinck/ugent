cmake_minimum_required(VERSION 2.8.4)
project(Reeks_9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic")

file(GLOB_RECURSE SOURCE_FILES *.cpp *.h)

add_executable(Reeks_9 ${SOURCE_FILES})