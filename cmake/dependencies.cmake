include(FetchContent)

if (NOT TARGET HDF5)
	FetchContent_Declare( HDF5
		GIT_REPOSITORY https://github.com/HDFGroup/hdf5
		GIT_TAG        origin/develop
		)
	FetchContent_MakeAvailable( HDF5 )
endif()

target_link_libraries(WMP
	INTERFACE hdf5
	INTERFACE hdf5_cpp
	INTERFACE cerf::cerfcpp
	)
