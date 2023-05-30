
typedef std::shared_ptr<H5::H5File> h5fileptr;

h5fileptr openhdf(const std::string& filename)
{
	std::cout << H5F_ACC_RDONLY << std::endl; 
	H5::Exception::dontPrint();
	H5::H5File* f = 0;
	try {
		f = new H5::H5File(filename.c_str(),H5F_ACC_RDONLY);	
	} catch(const H5::FileIException&) {
		f = new H5::H5File(filename.c_str(), H5F_ACC_TRUNC);
	}
	return h5fileptr(f); 

}

<<<<<<< HEAD
std::vector
=======


typedef std::shared_ptr<H5::Group> grp_ptr;

grp_ptr get_iso_grp(const H5::H5std_string ISO_NAME); 
>>>>>>> b0141ad (tuesday commits, hdf5 dataset reader fixed, moving functionality of WMP.cpp to header file)





<<<<<<< HEAD


void test_find(h5fileptr filename)
{
	H5::H5File f = *filename; 
	std::cout << f.getFileSize() << std::endl;
	
}
=======
>>>>>>> b0141ad (tuesday commits, hdf5 dataset reader fixed, moving functionality of WMP.cpp to header file)
