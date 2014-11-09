cmake_minimum_required(VERSION 2.8.4)
project(Reeks_5)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -std=c89 -pthread")

set(SOURCE_FILES oef45.c)
add_executable(Reeks_5 ${SOURCE_FILES})