cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(hello_world VERSION 1.0)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(hello_world hello.c foo.c)
