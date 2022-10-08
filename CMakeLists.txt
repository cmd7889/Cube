cmake_minimum_required(VERSION 3.21)
project(ProgrammingLabs)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab main.cpp Cube.h Cube.cpp SolveCube.cpp SolveCube.h)

set(FMT_LIB "d:/itmo/rubik/fmt/include")
include_directories(${FMT_LIB})

set(CMAKE_EXE_LINKER_FLAGS "-static")