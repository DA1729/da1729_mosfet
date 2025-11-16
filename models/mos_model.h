#include <cmath>
#include <algorithm>

struct mosfet_output {
	double i_d;
	double g_m;
	double g_ds;
};



class mosfet_model{
	private:
		const double v_th;
		const double k;

	public:
		mosfet_model(double v_th, double u_cox_wl): v_th(v_th), k(u_cox_wl) {}


		mosfet_output calculate(double v_gs, double v_ds);
};
