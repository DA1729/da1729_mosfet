#include "../models/square_law/mos_model.h"
#include <iostream>
#include <iomanip>

int main() {
	double v_th = 0.5;
	double k = 1e-3;

	mosfet_model nmos(v_th, k);

	double v_gs = 1.0;
	double v_ds = 1.5;

	mosfet_output out = nmos.calculate(v_gs, v_ds);

	double v_ov = v_gs - v_th;
	double v_ds_sat = v_ov;

	std::string region;
	if (v_gs <= v_th) {
		region = "cutoff";
	} else if (v_ds < v_ds_sat) {
		region = "triode";
	} else {
		region = "saturation";
	}

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "operating point analysis\n\n";
	std::cout << "device parameters:\n";
	std::cout << "  v_th = " << v_th << " v\n";
	std::cout << "  k = " << k << " a/v^2\n\n";

	std::cout << "bias conditions:\n";
	std::cout << "  v_gs = " << v_gs << " v\n";
	std::cout << "  v_ds = " << v_ds << " v\n";
	std::cout << "  v_ov = " << v_ov << " v\n";
	std::cout << "  v_ds_sat = " << v_ds_sat << " v\n\n";

	std::cout << "operating region: " << region << "\n\n";

	std::cout << "dc characteristics:\n";
	std::cout << "  i_d = " << out.i_d * 1e3 << " ma\n\n";

	std::cout << "small-signal parameters:\n";
	std::cout << "  g_m = " << out.g_m * 1e3 << " ma/v\n";
	std::cout << "  g_ds = " << out.g_ds * 1e6 << " ua/v\n";

	if (out.g_m > 0) {
		std::cout << "  g_m/i_d = " << (out.g_m / out.i_d) << " v^-1\n";
	}

	return 0;
}
