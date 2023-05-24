#include "WMP.hpp"

using namespace H5;
const std::string& FILE_NAME("019039.h5");
const std::string& DATASET_NAME("DATA");



int main(void)
{
	WMP::h5fileptr f = WMP::test_read(FILE_NAME);
	WMP::test_find(f);
}
