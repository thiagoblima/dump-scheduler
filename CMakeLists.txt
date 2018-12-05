# cmake_minimum_required(VERSION VERSION 2.6)

set(CMAKE_C_COMPILER "C:/cygwin64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/cygwin64/bin/g++.exe")

project(Schedule)

set(CMAKE_CXX_STANDARD 11)

add_executable(Schedule main.cpp)