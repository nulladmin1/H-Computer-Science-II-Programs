cmake_minimum_required(VERSION 3.20)

project(polynomial)

set(CMAKE_CXX_STANDARD 23)

add_library(polynomial_lib STATIC Polynomial.cpp)
target_include_directories(polynomial_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
