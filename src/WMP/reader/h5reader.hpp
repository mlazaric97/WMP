typedef std::shared_ptr<H5::Group>  h5fileptr; 
typedef std::shared_ptr<H5::Group>  h5grpptr; 
//typedef std::shared_ptr<H5::DataSet> h5dsptr; 


// opens and returns a pointer to and hdf5 file denoted by FILENAME; 
H5::H5File openhdf(const H5std_string FILENAME)
{	
	std::cout << "Opening data file: " << FILENAME << std::endl; 
	H5::Exception::dontPrint();
	
	H5::H5File f; 
	try { 
		f = H5::H5File(FILENAME,H5F_ACC_RDONLY);
	} catch( const H5::FileIException error) {	
		std::cout << "ERROR OPENING DATAFILE: " << FILENAME << std::endl;
		error.printErrorStack(); 
		exit; 
	}
	return f; 
}

// Opens the "/" group at root of all WMP_library files
// then opens the isotope group denoted by GROUPNAME and returns a pointer to it 
H5::Group open_isogroup(const H5std_string GROUPNAME,H5::H5File &file)
{
	std::cout << "Opening Group: '/'" << std::endl; 
	H5::Exception::dontPrint();
	H5::Group g, isog;
	try {
		g = file.openGroup("/"); 
	} catch( const H5::GroupIException erro) {
		std::cout << "ERROR OPENING BASE GROUP" << std::endl; 
		erro.printErrorStack(); 
		exit; 
	}
	std::cout << "Opened Group:" << GROUPNAME << std::endl << "Opening Isotope Group\n";	
	try {
		 isog = g.openGroup(GROUPNAME);
	} catch( const H5::GroupIException error) {
		std::cout << "ERROR OPENING ISOTOPE GROUP" << std::endl; 
		error.printErrorStack();
		exit; 
	}	
	std::cout << "Successfully opened Isotope Group: "<< GROUPNAME << std::endl; 
	
	return isog; 
}

void get_E_max(H5::Group &isogroup)
{
	H5::Exception::dontPrint();

	H5::DataSet ds;
	try {	
		ds = isogroup.openDataSet("E_max"); 
	} catch(const H5::FileIException error) {
		std::cout << "ERROR OPENING DATASET: 'E_max'\n";
		error.printErrorStack();
		exit; 
	}
	std::cout << "Successfully opened DataSet 'E_max' " << std::endl; 

}


/*

h5fileptr openhdf(const H5std_string FILE_NAME)
{
	H5::H5File *f = 0; 
	try {
		f = new H5::H5File(FILE_NAME, H5F_ACC_RDONLY); 

	} catch(const H5::FileIException&) {
		std::cout << "ERROR OPENING DATAFILE: " << FILE_NAME << std::endl; 
		exit; 
	}
	std::cout << "Succesfully opened data file " << std::endl; 

	return h5fileptr(f); 

}
*/
void closehdf(h5fileptr file) 
{
	file->close(); 
}

h5grpptr get_iso_grp(const H5std_string ISO_NAME, h5fileptr fileptr)
{
	std::cout << "Grabbing Data for Isotope: " << ISO_NAME << std::endl; 	
	
	H5::Exception::dontPrint();

	H5::Group g;
	H5::Group isog; 
	H5std_string BG_NAME("/");
	try {   
		g = fileptr->openGroup(BG_NAME);
	} catch(const H5::FileIException&) {
		std::cout << "ERROR: CANNOT OPEN '/' GROUP" << std::endl; 
	}

	try {
		isog = g.openGroup(ISO_NAME); 
	} catch(const H5::FileIException&) {
		std::cout << "ERROR OPENING ISOTOPE GROUP IN DATA FILE" << std::endl; 
		exit; 
	}
	std::cout << "Successfully opened " << ISO_NAME << " group" << std::endl; 
	return h5grpptr(&isog); 

}


void get_emax(const H5std_string dsname, h5grpptr isotope_group)
{
	std::cout << "reading dataset: '" << dsname << "'\n";
	H5::Group ig = *isotope_group; 	

	H5::DataSet ds; 
	try{
		ds = ig.openDataSet(dsname);}
	catch(const H5::GroupIException error) {
		std::cout << "ERROR: Cannot open dataset: '"<< dsname <<"' in file" << std::endl; 
		error.printErrorStack();
		exit;
	}
	
		
	std::cout << "here2" << std::endl; 




}



