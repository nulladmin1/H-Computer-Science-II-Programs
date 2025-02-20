cmake_minimum_required(VERSION 3.20)

project(programs)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(fraction)
install(TARGETS fraction DESTINATION bin)

add_subdirectory(eightQueens)
install(TARGETS eightQueens DESTINATION bin)

add_subdirectory(plague)
install(TARGETS plague DESTINATION bin)
