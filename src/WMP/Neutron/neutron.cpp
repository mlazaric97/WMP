// Class definition for WMP evaluation for incident neutron
// Used MIT's WMP_library as inpsiration for setup of problem
// Member functions will be able to : 
// 	- calculate cross section at specified temperature
// 	- Windowing optional to allow for calculation of sensitivities
// 	- calculate sensitivities to Real(pole_j) Imag(pole_j) |r_j|, 
// 	- Re(r_j), Im(r_j), a_c, 

class Neutron { 
	private: 
	std::vector<std::vector<std::vector<double>>> curvefit;
	std::vector<std::vector<std::complex<double>>> data; 	
	std::vector<std::vector<int>> windows;
//	std::vector<float> ceoff; commented out as I think this is a mistake
       	std::vector<int> broaden_poly; 	
	std::string name;  
	int order,fissionable; 
	double E_min,E_max,spacing;



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
	
	// accessor functions
	double grab_curvefit(int window_id, int order, int rxn);
	std::complex<double> grab_data(int window_id, int rxn);
	std::vector<int>   grab_windows(int window_id); // goal for this one is to call a window and a size 2 array of ints
	int    grab_broaden_poly(int window_id);
	int    grab_order();
	int    grab_fissionable(); 
	double grab_E_min(); 
	double grab_E_max(); 
	double grab_spacing(); 

	// Current ctor takes the filename as a string, 
	// To do: copy constructor, more options for constructor (i.e. H5File arg etc.)
	
	#include "ctor/ctor.cpp"
	// data setup as in WMP_library for convenience
	// data[i][0] is a pole data[i][1:] are the partial residues
	std::vector<double> xs(double energy, double temp); // returns vector of xs at given E and T might make it private then only access it through xss 
							    // (or whatever the vector version of the function is called)   
	std::vector<std::vector<double>> WMP(std::vector<double> Energies, double temp);		
}; 

// grab_xxx defintions
// 

double Neutron::grab_curvefit(int window_id, int order, int rxn)
{
	return this->curvefit[window_id][order][rxn]; 
}

std::complex<double> Neutron::grab_data(int window_id, int rxn) 
{
	return this->data[window_id][rxn];
}

std::vector<int>   Neutron::grab_windows(int window_id)
{
	return this->windows[window_id];
}

int    Neutron::grab_broaden_poly(int window_id)
{
	return this->broaden_poly[window_id];
}

int    Neutron::grab_order()
{
	return this->order; 
}

int    Neutron::grab_fissionable()
{
	return this->fissionable;
}

double Neutron::grab_E_min()
{
	return this->E_min; 
}

double Neutron::grab_E_max() 
{
	return this->E_max; 
}

double Neutron::grab_spacing() 
{
	return this->spacing;
}

// end grab_xxx definitions; 


std::vector<double> Neutron::xs(double E, double temp) 
{
	double ss{},sa{},sf{},st{}; // intializing cross sections to zero, sa = sigma absorption
	double sqrtE = sqrt(E); 
	int window_i = floor((sqrtE - sqrt(E_min))/spacing);
	int startw = windows[window_i][0] - 1; 
	int endw   = windows[window_i][1];
	double pwr; 
	if (temp == 0. || not(broaden_poly[window_i]))
	{
		pwr = 1./E; 
		for (int j{}; j < order; ++j)
		{
			ss += curvefit[window_i][j][0]*pwr; 
			sa += curvefit[window_i][j][1]*pwr; 
			if (fissionable) 
				sf += curvefit[window_i][j][2]*pwr; 
		
			pwr *= sqrtE; 
		}
		for (int i = startw; i < endw; ++i)
		{
			std::complex<double> j(0,1); 
			std::complex<double> temp,common; 
			temp = (sqrtE - data[i][0]);
			common = j/temp/E; 
			ss += (data[i][1]*common).real(); 
			sa += (data[i][2]*common).real();

		}
	}
	else
	{
		std::cout << "ERROR: DOPPLER BROADENED CROSS SECTIONS ARE A WORK IN PROGRESS\n SET TEMPERATURES TO 0K AND TRY AGAIN" << std::endl;
	}

	
	st = ss + sa + sf;
	std::vector<double> sigmas{st,sa,sf}; 
	
	return sigmas; 
}

std::vector<std::vector<double>> Neutron::WMP(std::vector<double> E, double T)
{
	int l = E.size();
	std::vector<std::vector<double>> xs_vec(l,std::vector<double>(3,0.0)); // same length as the E vector, 3 xs's per energy total, absorption
									       // fission 
	
	for (int i{}; i < l; ++i)
	{
		xs_vec[i] = xs(E[i],T); 
	}
	return xs_vec; 
}
