add_executable(WMP_cpp.exe WMP.cpp)
	
target_link_libraries(WMP_cpp.exe
	WMP_LIB	
	)

add_compile_options(-O3 -Wall)
