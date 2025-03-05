cmake_minimum_required(VERSION 3.20)

project(programs)

set(cmake_cxx_standard 23)

add_subdirectory(fraction)

add_executable(fraction_exe fraction/Source.cpp)
target_link_libraries(fraction_exe PRIVATE fraction_lib)

install(TARGETS fraction_exe RUNTIME DESTINATION bin)
install(TARGETS fraction_lib DESTINATION lib)

add_subdirectory(polynomial)

add_executable(polynomial_exe polynomial/Source.cpp)
target_link_libraries(polynomial_exe PRIVATE polynomial_lib)

install(TARGETS polynomial_exe RUNTIME DESTINATION bin)
install(TARGETS polynomial_lib DESTINATION lib)
