
Neutron(std::string filename)
{
	// open file
	H5::H5File file = openhdf(filename);	
	// find atomic symbol and number 
	this->name = get_symb(file); 

	// open Isotope Group
	H5::Group isogroup = open_isogroup(name,file); 
	// populate class from Isotope Group
	
	this->broaden_poly = get_bp(isogroup);
	this->curvefit = get_curvefit(isogroup); 


	// close file
	
	// return







}
