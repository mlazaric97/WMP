add_executable(WMP_fortran.exe WMP.F90)

target_link_libraries(WMP_fortran.exe WMP_LIB)

add_compile_options(-03 -Wall) 
