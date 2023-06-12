
Neutron(std::string filename)
{
	// open file
	H5::H5File file = openhdf(filename);	
	// find atomic symbol and number 
	this->name = get_symb(file); 

	// open Isotope Group
	H5::Group isogroup = open_isogroup(name,file); 
	// populate class from Isotope Group
	
	// Could combine these all into one function "get_h5" not neccesary as of yet	
	this->broaden_poly = get_bp(isogroup);
	this->curvefit = get_curvefit(isogroup); 
	this->E_min = get_E_bounds(isogroup,"E_min");
       	this->E_max = get_E_bounds(isogroup,"E_max"); 	
	this->data = get_data(isogroup); 
	this->windows = get_windows(isogroup); 

	std::cout << "Finished loading in data for: '" << this->name << "'\n";	
	// close file
	file.close();
	// I think this is all we need to do to make sure there are no memory leaks from reading in data
	// Any suggestions would be welcome

}
