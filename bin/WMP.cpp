#include "WMP.hpp"

using namespace H5;
<<<<<<< HEAD
const std::string& FILE_NAME("019039.h5");
const std::string& DATASET_NAME("DATA");
=======
const H5std_string FILE_NAME("019039.h5");
const H5std_string BASE_GROUP("/");
const H5std_string ISO_GROUP("K39");
const H5std_string DATASET_NAME("E_max");
>>>>>>> b0141ad (tuesday commits, hdf5 dataset reader fixed, moving functionality of WMP.cpp to header file)



int main(void)
{
<<<<<<< HEAD
	WMP::h5fileptr f = WMP::test_read(FILE_NAME);
	WMP::test_find(f);
=======
	Exception::dontPrint();

	H5File file(FILE_NAME, H5F_ACC_RDONLY);
	std::cout << "here" << std::endl; 

	Group bg = file.openGroup(BASE_GROUP);
	Group ig = bg.openGroup(ISO_GROUP);
	std::cout << "opened / group" << std::endl; 
	DataSet dataset = ig.openDataSet(DATASET_NAME);
	
	std::cout << "here 2" << std::endl; 

	H5T_class_t type_class = dataset.getTypeClass();
	
	std::cout << "here 3" << std::endl; 

	return 0; 
>>>>>>> b0141ad (tuesday commits, hdf5 dataset reader fixed, moving functionality of WMP.cpp to header file)
}
