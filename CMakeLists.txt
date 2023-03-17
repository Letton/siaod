cmake_minimum_required(VERSION 3.24)
project(siaod)

set(CMAKE_CXX_STANDARD 23)

add_executable(siaod main.cpp struct.h struct.cpp)
