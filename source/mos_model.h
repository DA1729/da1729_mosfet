#include <cmath>
#include <algorithm>

struct mosfet_output {
	double I_D;		// drain current
	double G_m;		// transconductance
	double G_ds;		// output conductance
};



class mosfet_model{
	private: 
		const double V_TH;
		const double K;

	public:
		mosfet_model(double vth, double u_cox_wl): V_TH(vth, K(u_cox_WL) {}


		mosfet_output calculate(double vgs, double vds);
};
