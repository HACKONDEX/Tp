cmake_minimum_required(VERSION 3.0)

project(lib_B)

set(SOURCES lib.cpp)
set(HEADERS lib.h)
add_library(lib_B ${SOURCES})

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib)


