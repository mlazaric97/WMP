#include "WMP.hpp"
using namespace H5;

const H5std_string FILE_NAME("019039.h5");
const H5std_string BASE_GROUP("/");
const H5std_string ISO_GROUP("K39");
const H5std_string DATASET_NAME("E_max");



int main(void)
{
	H5File file = WMP::openhdf(FILE_NAME);
	Group  isogrp = WMP::open_isogroup(ISO_GROUP,file); 	
	WMP::get_E_bounds(isogrp); 	
	WMP::get_bp(isogrp); 	
	WMP::get_curvefit(isogrp); 
	WMP::get_data(isogrp); 		
	
	
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
