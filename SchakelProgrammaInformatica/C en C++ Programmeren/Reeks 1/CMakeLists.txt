cmake_minimum_required(VERSION 2.8.4)
project(Reeks1)

set(SOURCE_FILES oef11.c)
add_executable(Reeks1 ${SOURCE_FILES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic")