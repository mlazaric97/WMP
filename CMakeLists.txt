cmake_minimum_required(VERSION 3.17)

project(WMP LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(WMP INTERFACE)
target_include_directories( WMP INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/)

include(./cmake/dependencies.cmake)
find_package( HDF5 REQUIRED COMPONENTS CXX)


add_compile_options(-O3 -Wall)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/bin/)

