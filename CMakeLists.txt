## PREAMBLE ## 
cmake_minimum_required(VERSION 3.17)
if(DEFINED PROJECT_NAME)
	set(SUBPROJECT ON)
else()
	set(SUBPROJECT OFF)
endif()

project(WMP LANGUAGES CXX C) 

enable_language(Fortran) 

## SETUP ## 
find_package(HDF5 REQUIRED COMPONENTS C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 



## DEPENDENCIES ## 
include(cmake/dependencies.cmake)

## LIBRARY SETUP ## 
add_library(WMP_LIB INTERFACE)

target_include_directories(WMP_LIB
	INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/src/
	src/

	)

target_link_libraries(WMP_LIB
	INTERFACE ${HDF5_LIBRARIES}
	INTERFACE ${HDF5_CXX_LIBRARIES}
	INTERFACE cerfcpp
	)


include_directories(	${HDF5_INCLUDE_DIR} 
			${HDF5_CXX_INCLUDE_DIRS}
		       	${CMAKE_SOURCE_DIR}/src/ 
			~/libcerf/lib/ 
			)

		## top level ## 

if(NOT SUBPROJECT) 
	add_subdirectory(bin)
	#	target_link_libraries(WMP 
	#	PUBLIC WMP_LIB
	#	)
endif()
