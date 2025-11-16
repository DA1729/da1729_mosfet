#include "../models/square_law/mos_model.h"
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	double v_th = 0.5;
	double k = 1e-3;
	double v_dd = 3.0;
	double r_d = 5000.0;
	double v_gs = 1.0;

	mosfet_model nmos(v_th, k);

	double v_ds_guess = v_dd / 2.0;
	double v_ds = v_ds_guess;

	for (int i = 0; i < 100; ++i) {
		mosfet_output out = nmos.calculate(v_gs, v_ds);
		double v_ds_new = v_dd - out.i_d * r_d;

		if (std::abs(v_ds_new - v_ds) < 1e-6) {
			v_ds = v_ds_new;
			break;
		}
		v_ds = v_ds_new;
	}

	mosfet_output dc_op = nmos.calculate(v_gs, v_ds);

	double a_v = -dc_op.g_m * r_d / (1.0 + dc_op.g_ds * r_d);

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "common-source amplifier analysis\n\n";
	std::cout << "circuit parameters:\n";
	std::cout << "  v_dd = " << v_dd << " v\n";
	std::cout << "  r_d = " << r_d << " ohm\n";
	std::cout << "  v_gs = " << v_gs << " v\n\n";

	std::cout << "dc operating point:\n";
	std::cout << "  v_ds = " << v_ds << " v\n";
	std::cout << "  i_d = " << dc_op.i_d * 1e3 << " ma\n\n";

	std::cout << "small-signal parameters:\n";
	std::cout << "  g_m = " << dc_op.g_m * 1e3 << " ma/v\n";
	std::cout << "  g_ds = " << dc_op.g_ds * 1e6 << " ua/v\n\n";

	std::cout << "voltage gain:\n";
	std::cout << "  a_v = " << a_v << "\n";

	return 0;
}
