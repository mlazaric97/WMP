// Class definition for WMP evaluation for incident neutron
// Used MIT's WMP_library as inpsiration for setup of problem
// Member functions will be able to : 
// 	- calculate cross section at specified temperature
// 	- Windowing optional to allow for calculation of sensitivities
// 	- calculate sensitivities to Real(pole_j) Imag(pole_j) |r_j|, 
// 	- Re(r_j), Im(r_j), a_c, 


class neutron { 
	private: 

	H5::H5File h5file; 



	public:
	#include "ctor/ctor.hpp"
	// data setup as in WMP_library for convenience
	// data[i][0] is a pole data[i][1:] are the partial residues
	
	std::vector<std::vector<std::complex<double>>> data; 
	
	
	std::vector<double> windows;// might be better as a list of ints
	// where ints represent index of energy grid
	std::vector<double> coeff; 


	std::string filename; 
	double A;   // atomic weight (NOT Atomic weight ratio)
	double beta; // temperature 


}; 
