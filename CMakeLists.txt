cmake_minimum_required(VERSION 3.20)

project(programs)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(fraction)

install(TARGETS fraction DESTINATION bin)
