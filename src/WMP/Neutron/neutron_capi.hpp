//#ifdef __cplusplus
extern "C" {
//#endif 

Neutron* neutron; 
void Ntrn(const char* filelocation, bool verbose) 
{
	if (neutron != 0){delete neutron;}
	neutron = new Neutron(std::string(filelocation),verbose);
}

double Ntrn_getcurvefit(int window_id, int order, int rxn)
{
	return neutron->grab_curvefit(window_id, order, rxn);
}

std::complex<double> Ntrn_getdata(int window_id, int rxn)
{
	return neutron->grab_data(window_id,rxn);
}

std::vector<int> Ntrn_getwindows(int window_id)
{
	return neutron->grab_windows(window_id);
}

int Ntrn_getbp(int window_id)
{
	return neutron->grab_broaden_poly(window_id); 
}

int Ntrn_getorder()
{
	return neutron->grab_order(); 
}

int Ntrn_getfissionable()
{
	return neutron->grab_fissionable(); 
}

double Ntrn_getemin() 
{
	return neutron->grab_E_min(); 
}

double Ntrn_getemax()
{
	return neutron->grab_E_max(); 
}

double Ntrn_getspacing()
{
	return neutron->grab_spacing();
}



//#ifdef __cplusplus
}
//#endif
