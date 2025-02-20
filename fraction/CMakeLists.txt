cmake_minimum_required(VERSION 3.20)

project(fraction)

set(CMAKE_CXX_STANDARD 23)

add_library(fraction_lib STATIC Fraction.cpp)
target_include_directories(fraction_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
