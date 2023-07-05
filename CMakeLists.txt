cmake_minimum_required(VERSION 3.17)

project(WMP LANGUAGES CXX C)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(HDF5 REQUIRED COMPONENTS C CXX )
#find_package(cerf REQUIRED ON) can't get it working :/ 




include_directories(${HDF5_INCLUDE_DIR}
       		    ${HDF5_CXX_INCLUDE_DIRS}
		    ${CMAKE_SOURCE_DIR}/src/) #cerf_DIR

add_compile_options(-O3 -Wall)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/bin/)

