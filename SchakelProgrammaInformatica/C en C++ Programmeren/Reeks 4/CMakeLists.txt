cmake_minimum_required(VERSION 2.8.4)
project(Reeks_4)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -std=c89")

set(SOURCE_FILES oef39.c)
add_executable(Reeks_4 ${SOURCE_FILES})