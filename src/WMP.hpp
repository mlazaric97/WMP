#pragma once

#include <iostream>
#include <string> 
#include <vector> 
#include <complex>
#include <memory>
#include "H5Cpp.h"
#define CERF_AS_CPP // required for #include cerf.h statement
#include "cerf.h" 
#include <tuple>



namespace WMP {
	#include "WMP/reader.hpp"
	#include "WMP/Neutron.hpp"
	#include "WMP/tools.hpp"


}
