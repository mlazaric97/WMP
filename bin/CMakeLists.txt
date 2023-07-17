add_executable(WMP.exe WMP.cpp)
	
target_link_libraries(WMP.exe 
	${HDF5_LIBRARIES}
	cerf::cerf
	)
