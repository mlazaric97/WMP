#include "WMP.hpp"

#define CERF_AS_CPP
#include "cerf.h"
//#include "w_of_z.c"
const std::string FILE_NAME("092238.h5");
const std::string BASE_GROUP("/");
const std::string ISO_GROUP("U238");
const std::string DATASET_NAME("E_max");


int main(void)
{
	WMP::Neutron nn(FILE_NAME, false); 
	_cerf_cmplx j{12,34};

	
//	std::complex<double> fad = w_of_z(j);
	std::cout << "j = " << j << std::endl; 
//	std::cout << "fad = " << fad << std::endl; 	
	std::cout << "fad = " << w_of_z(j) << std::endl; 

	/* commenting out this
	   Faddeeva function attempts are here 
	std::cout << "b[0] = " << b[0] << std::endl; 
	std::cout << "b[1] = " << b[1] << std::endl; 
	std::cout << "b[2] = " << b[2] << std::endl; 
	std::cout << "b[3] = " << b[3] << std::endl; 
	std::cout << "b[4] = " << b[4] << std::endl; 
	std::cout << "b[5] = " << b[5] << std::endl; 

	*/
//	_Complex double kk{12,34};
//	_Complex double fad = cerf(kk);

//	std::cout << "kk = " << kk << std::endl; 
	/*
	H5File file = WMP::openhdf(FILE_NAME);
	Group  isogrp = WMP::open_isogroup(ISO_GROUP,file); 	
	WMP::get_E_bounds(isogrp); 	
	WMP::get_bp(isogrp); 	
	WMP::get_curvefit(isogrp); 
	WMP::get_data(isogrp); 		
	WMP::get_windows(isogrp); 	
	WMP::get_symb(file);	
	*/

//	WMP::h5grpptr  iso_grp = WMP::get_iso_grp(ISO_GROUP,data_file);
//	DataSet emax = iso_grp->openDataSet(DATASET_NAME); 

	std::cout << "PROGRAM FINISHED WITHOUT ERRORS\nGOODBYE" << std::endl; 
	return 0; 
}
