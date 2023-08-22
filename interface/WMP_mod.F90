module wmp_interface_mod
        ! This was built to create Windowed Multipole cross sections in MCNP
        ! the intention is to have a code that will produce cross sections in C, C++ and Fortran 90
!        use ISO_FORTRAN_ENV, only : REAL64

        use, intrinsic : iso_c_binding

        implicit none


        public :: WMP

        interface
                subroutine Ntrn(filename,verb) bind(c, name="Ntrn")
                import :: c_bool, c_char
                CHARACTER, intent(in), value :: filename
                LOGICAL




end module wmp_interface_mod

