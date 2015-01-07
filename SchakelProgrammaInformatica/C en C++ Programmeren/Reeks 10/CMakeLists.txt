cmake_minimum_required(VERSION 2.8.4)
project(Reeks_10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic")

file(GLOB_RECURSE SOURCE_FILES oef129/*)

add_executable(Reeks_10 ${SOURCE_FILES})