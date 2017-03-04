cmake_minimum_required(VERSION 3.3)
project(test_serialize)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("include")
set(SOURCE_FILES demo/test_serialize.cpp)
add_executable(test_serialize ${SOURCE_FILES})