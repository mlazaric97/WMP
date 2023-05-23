include(FetchContent)

if (NOT TARGET HDF5)
	FetchContent_Declare( hdf5
		GIT_REPOSITORY https://github.com/HDFGroup/hdf5
		GIT_TAG        origin/develop
		)
	FetchContent_MakeAvailable( hdf5 )
endif()

target_link_libraries(WMP
	INTERFACE HDF5::HDF5
	)
