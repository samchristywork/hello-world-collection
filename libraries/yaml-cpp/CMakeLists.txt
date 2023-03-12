cmake_minimum_required(VERSION 3.25)

project(yaml_example)

add_definitions(-std=c++11)

set(src main.cpp)
add_executable(yaml_example ${src})

target_link_libraries(yaml_example ${CMAKE_HOME_DIRECTORY}/yaml-cpp/build/libyaml-cpp.a)
