#ifdef __cplusplus
extern "C" {
#endif 

Neutron* neutron; 

// ctor shell
void Ntrn(const char* filelocation, bool verbose) 
{
	if (neutron != 0){delete neutron;}
	neutron = new Neutron(string(filelocation),verbose);
{

double Ntrn_getcurvefit(int window_id, int order, int rxn)
{
	return neutron->get_curvefit(window_id, order, rxn);
}

double Ntrn_getdata(int window_id, int rxn)
{
	return neutron->get_data(window_id,rxn);
}

int* Ntrn_getwindows(int window_id)
{
	return neutron->get_windows(window_id);
}

int Ntrn_getbp(int window_id)
{
	return neutron->get_broaden_poly(window_id); 
}

int Ntrn_getorder()
{
	return neutron->get_order(); 
}

int Ntrn_getfissionable()
{
	return neutron->get_fissionable(); 
}

double Ntrn_getemin() 
{
	return neutron->get_E_min(); 
}

double Ntrn_getemax()
{
	return neutron->get_E_max(); 
}

double Ntrn_getspacing()
{
	return neutron->get_spacing();
}



#ifdef __cplusplus
}
#endif
