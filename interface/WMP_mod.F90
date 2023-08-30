module WMP_mod
        ! This was built to create Windowed Multipole cross sections in MCNP
        ! the intention is to have a code that will produce cross sections in C, C++ and Fortran 90
!        use ISO_FORTRAN_ENV, only : REAL64

        use, intrinsic :: iso_c_binding

        implicit none


        public :: Ntrn

        interface
                subroutine Ntrn_call(filename,verb) bind(c, name="Ntrn")
                import :: c_int, c_char
                character(c_char), dimension(*), intent(in) :: filename
                integer, intent(in), value :: verb
                end subroutine  
        end interface
contains
        subroutine Ntrn(filename,verb)
                character, intent(in) :: filename
                integer, intent(in) :: verb
                call ntrn_call(filename, int(verb,c_int))
        end subroutine ntrn


end module WMP_mod



