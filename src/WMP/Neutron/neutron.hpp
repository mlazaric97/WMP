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
	std::vector<std::vector<int>> windows;
//	std::vector<float> ceoff; commented out as I think this is a mistake
       	std::vector<int> broaden_poly; 	
	std::string name;  
	int order; 
	float E_min,E_max,spacing;
	// Description of Member variales;
	// Curvefit - holomorphic peice of the cross section
	// Curvefit[i] - curve fit polynomials for the i'th window  
	// Curvefit[i][j] - curve fit polynomials for the E^(-1 +j)'th order term for total, abs, fiss xs's 
	// 
	// data - Contains the poles and residues 
	// data[i][0] -  retrieves the i'th pole
	// data[i][1:]- retrieves the residues total, absorption, fission 
	//
	//
	// 
	// windows - list of integer pairs dictating the indicies of each window 
	// windows[i] = [j,k] where j and k represent the first and last index of the windows respectively


	public:


	// Current ctor takes the filename as a string, 
	// To do: copy constructor, more options for constructor (i.e. H5File arg etc.)
	
	#include "ctor/ctor.hpp"
	// data setup as in WMP_library for convenience
	// data[i][0] is a pole data[i][1:] are the partial residues
 	
	std::vector<float> xs(float energy, float temp, int mt = 1); // returns scalar  
		
}; 


std::vector<float> Neutron::xs(float E, float temp, int mt) 
{
	float st{},sa{},sf{}; // intializing cross sections to zero, sa = sigma absorption
	int window_i = floor((E - E_min)/spacing);
	int startw = windows[window_i][0] - 1; 
	int endw   = windows[window_i][1]; 
	float sqrtE = sqrt(E); 
	if (temp == 0.)
	{
		temp = 1.0/E; 
		for (int i = startw; i < endw; ++i)
		{
			for (int j{}; j < order; ++j)
			{

			}

		}	



	}
	else	std::cout << "ERROR: DOPPLER BROADENED CROSS SECTIONS ARE A WORK IN PROGRESS\n SET TEMPERATURES TO 0K AND TRY AGAIN" << std::endl;




	std::vector<float> sigmas{st,sa,sf}; 
	return sigmas; 


}

