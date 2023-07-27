include(FetchContent)

if (NOT HDF5_FOUND)
	FetchContent_Declare( hdf5
		GIT_REPOSITORY https://github.com/HDFGroup/hdf5
		GIT_TAG        origin/develop
		)
	FetchContent_MakeAvailable( hdf5 )
endif()

FetchContent_Declare( libcerf
	GIT_REPOSITORY https://jugit.fz-juelich.de/mlz/libcerf
	GIT_TAG	       origin/main
	)

#INTERFACE -DCERF_CPP=ON
set(CERF_CPP ON)

FetchContent_MakeAvailable( libcerf )


get_property(libcerf_location INSTALL libcerf PROPERTY LOCATION)
message(STATUS "libcerf location = " ${libcerf_location})
