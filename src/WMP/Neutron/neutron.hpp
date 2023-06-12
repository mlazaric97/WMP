// Class definition for WMP evaluation for incident neutron
// Used MIT's WMP_library as inpsiration for setup of problem
// Member functions will be able to : 
// 	- calculate cross section at specified temperature
// 	- Windowing optional to allow for calculation of sensitivities
// 	- calculate sensitivities to Real(pole_j) Imag(pole_j) |r_j|, 
// 	- Re(r_j), Im(r_j), a_c, 


class Neutron { 
	private: 
	std::vector<std::vector<std::vector<float>>> curvefit;
	std::vector<std::vector<std::complex<float>>> data; 	
	std::vector<std::tuple<int,int>> windows;
	std::vector<float> ceoff;
       	std::vector<int> broaden_poly; 	
	std::string name;  

	float E_min,E_max;
	// Description of Member variales;
	// Curvefit - holomorphic peice of the cross section
	// data - data[i][0] retrieves the i'th pole
	// 	- data[i][1] retrieves the total (?) residue 
	


	public:
	#include "ctor/ctor.hpp"
	// data setup as in WMP_library for convenience
	// data[i][0] is a pole data[i][1:] are the partial residues
	void print_cf(int i, int j)
	{
	size_t length = curvefit[i][j].size(); 
	
	
	std::cout << "\nPrinting Curvefit Value:\n (" << i <<"," << j 
		  << "," << ":" << length << ") =";
	for (int k{}; k <= length; ++k)
	{
		std::cout << curvefit[i][j][k] << ", ";	
	}
	std::cout << std::endl; 	
	
	}
 	
	




}; 
