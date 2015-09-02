
cmake_minimum_required(VERSION 2.8)

project(CSVReader)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

include_directories(../include)
include_directories(../src)

add_library(CSVReader STATIC
    ../src/_test.cpp
    ../src/CSVStream.cpp
    ../src/TokenStream.cpp
)

