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

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "mosfet parameters:\n";
	std::cout << "  v_th = " << v_th << " v\n";
	std::cout << "  k = " << k << " a/v^2\n\n";

	std::cout << "operating point:\n";
	std::cout << "  v_gs = " << v_gs << " v\n";
	std::cout << "  v_ds = " << v_ds << " v\n\n";

	std::cout << "results:\n";
	std::cout << "  i_d = " << out.i_d * 1e3 << " ma\n";
	std::cout << "  g_m = " << out.g_m * 1e3 << " ma/v\n";
	std::cout << "  g_ds = " << out.g_ds * 1e3 << " ma/v\n";

	return 0;
}
