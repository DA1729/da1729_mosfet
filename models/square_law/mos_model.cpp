#include "mosfet_model.h"


const double EPS = 1e-9;



mosfet_output mosfet_model::calculate(double v_gs, double v_ds){
	mosfet_output result = {0.0, 0.0, 0.0};


	double v_ov = std::max(0.0, v_gs - v_th);


	double v_ds_sat = v_ov;

	double v_ds_eff = std::min(v_ds, v_ds_sat);

	if (v_ov < EPS) {
		result.i_d = 0;
		result.g_m = 0;
		result.g_ds = 0;
	} else {
		result.i_d = k * (v_ov * v_ds_eff - 0.5 * v_ds_eff * v_ds_eff);



		if (v_ds < v_ds_sat) {
			result.g_m = k * v_ds;
			result.g_ds = k * (v_ov - v_ds);
		}


		else {
			result.g_m = k * v_ov;
			result.g_ds = 0.0;
		}
	}


	return result;
}

