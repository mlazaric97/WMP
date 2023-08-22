add_executable(WMP.exe WMP.F90)

target_link_libraries(WMP.exe WMP_LIB)

add_compile_options(-03 -Wall) 
