cmake_minimum_required(VERSION 3.17)
project(untitled6)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled6 main.cpp ModernStateContext.h States.cpp States.h LegacyStateContext.h SemiOOPStateContext.h nanobench.cpp nanobench.h)