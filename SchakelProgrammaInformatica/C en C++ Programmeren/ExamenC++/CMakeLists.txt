cmake_minimum_required(VERSION 2.8.4)
project(ExamenC__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES Oef130/*)
add_executable(ExamenC__ ${SOURCE_FILES})