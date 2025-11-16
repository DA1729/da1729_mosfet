#include "mosfet_model.h"


const double EPS = 1e-9;



mosfet_output mosfet_model::calculate(double vgs, double vds){
	model_output result = {0.0, 0.0, 0.0};


	// overdrive voltage
	double v_ov = std::max(0.0, vgs - vth);


	double vds_sat = v_ov;
	
	double vds_eff = std::min(vds, vds_sat);

	if (v_ov < EPS) {
		result.I_D = 0;
		result.G_m = 0;
		result.G_ds = 0;
	} else {
		result.I_D = K * (v_ov * vds_eff - 0.5 * vds_eff * vds_eff);



		if (vds < vds_sat) {
			result.G_m = K * vds;
			result.G_ds = K * (v_ov - vds);
		}


		else {
			result.G_m = K * v_ov;
			result.G_ds = 0.0;
		}
	}


	return result;
}

