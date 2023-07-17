#include "WMP.hpp"

using namespace H5;

const std::string FILE_NAME("092238.h5");
const std::string BASE_GROUP("/");
const std::string ISO_GROUP("U238");
const std::string DATASET_NAME("E_max");


int main(void)
{
	WMP::Neutron nn(FILE_NAME, false); 
	
	std::vector<std::vector<double>> sigmas; 
	double E = 100.; // eV
	std::vector<double> Es(10,0); 
	Es[0] = E; 
	for (int i = 1; i < Es.size(); ++i)
	{
		Es[i] = Es[i-1] + 1;
	}
	double T = 0.;   // K 

	std::vector<double> xss = nn.xs(E,T);
	sigmas = nn.WMP(Es,T); 
	
	std::cout << "ran xs(E,T)\n";
	std::cout << ISO_GROUP << " Total Cross section at E = " << E << "eV, T = " << T << "K, is: " << xss[0] << std::endl; 	
	std::cout << ISO_GROUP << " absorption CROSS SECTION AT E = " << Es[9] << "eV, T = " << T << "K, is: " << sigmas[9][2] << std::endl; 


	double a = 1.0; 
	double c = 3.0;
	std::vector<double> b = WMP::logspace(a,c,6);

	std::cout << "b[0] = " << b[0] << std::endl; 
	std::cout << "b[1] = " << b[1] << std::endl; 
	std::cout << "b[2] = " << b[2] << std::endl; 
	std::cout << "b[3] = " << b[3] << std::endl; 
	std::cout << "b[4] = " << b[4] << std::endl; 
	std::cout << "b[5] = " << b[5] << std::endl; 


	_cerf_cmplx j,fad; 
	j = _cerf_cmplx{0,1};
	fad = w_of_z(j);

	
	std::cout << "test = "  << j << std::endl; 
	std::cout << "test2 = " << fad << std::endl; 
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

/*
 
	WMP::h5fileptr data_file = WMP::openhdf(FILE_NAME);
	Group g1 = data_file->openGroup(BASE_GROUP);
	Group g2 = g1.openGroup(ISO_GROUP);
	DataSet emax = g2.openDataSet(DATASET_NAME);




	WMP::h5fileptr h5file = WMP::openhdf(FILE_NAME);
	WMP::h5grpptr  isogrp = WMP::get_iso_grp(ISO_GROUP,h5file); 
	std::cout << "Made it here" << std::endl; 
	WMP::get_emax(DATASET_NAME,isogrp);

*/

//	WMP::h5grpptr  iso_grp = WMP::get_iso_grp(ISO_GROUP,data_file);
//	DataSet emax = iso_grp->openDataSet(DATASET_NAME); 

	std::cout << "PROGRAM FINISHED WITHOUT ERRORS\nGOODBYE" << std::endl; 
	return 0; 
}
