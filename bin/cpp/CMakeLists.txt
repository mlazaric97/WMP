add_executable(WMP.exe WMP.cpp)
	
target_link_libraries(WMP.exe
	WMP_LIB	
	)

add_compile_options(-O3 -Wall)
