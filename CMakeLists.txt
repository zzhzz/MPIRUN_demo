cmake_minimum_required(VERSION 3.15)
project(small_demo)

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_CXX_STANDARD 11)
target_link_libraries(small_demo)
