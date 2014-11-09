cmake_minimum_required(VERSION 2.8.4)
project(Reeks2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -std=c89")

set(SOURCE_FILES oef23.c)
add_executable(Reeks2 ${SOURCE_FILES})