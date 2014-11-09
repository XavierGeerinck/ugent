cmake_minimum_required(VERSION 2.8.4)
project(voorbereiding_test)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic")

set(SOURCE_FILES linkedlist_add_sorted.c)
add_executable(voorbereiding_test ${SOURCE_FILES})