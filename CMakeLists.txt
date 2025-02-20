cmake_minimum_required(VERSION 3.20)

project(programs)

set(cmake_cxx_standard 23)

add_subdirectory(fraction)

add_executable(fraction_exe fraction/Source.cpp)
target_link_libraries(fraction_exe PRIVATE fraction_lib)

install(TARGETS fraction_exe RUNTIME DESTINATION bin)
install(TARGETS fraction_lib DESTINATION lib)
