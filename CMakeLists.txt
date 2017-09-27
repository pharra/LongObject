cmake_minimum_required(VERSION 3.8)
project(LongObject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LongObject.cpp LongObject.h IntBlockManager.cpp IntBlockManager.h Object.h)
add_executable(LongObject ${SOURCE_FILES})