#include "WMP.hpp"

using namespace H5;
const H5std_string FILE_NAME("019039.h5");
const H5std_string DATASET_NAME("DATA");



int main(void)
{
	Exception::dontPrint();

	H5File file(FILE_NAME, H5F_ACC_RDONLY);
	DataSet dataset = file.openDataSet(DATASET_NAME);
	H5T_class_t type_class = dataset.getTypeClass();

	return 0; 
}
