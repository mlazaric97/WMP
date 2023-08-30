program main

       use WMP_mod, only: ntrn

       character*9 :: filename ! files are in format ZZZAAA.h5 ! 
       integer :: verbose

      verbose = 0
      filename = "092238.h5" 
      call ntrn(filename, verbose) 
     
end program main

