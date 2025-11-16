#include "../models/square_law/mos_model.h"
#include <iostream>
#include <cmath>

bool test_gm_numerical() {
	mosfet_model nmos(0.5, 1e-3);
	double v_gs = 1.0;
	double v_ds = 1.5;
	double delta = 1e-6;

	mosfet_output out = nmos.calculate(v_gs, v_ds);
	mosfet_output out_plus = nmos.calculate(v_gs + delta, v_ds);

	double g_m_numerical = (out_plus.i_d - out.i_d) / delta;
	double error = std::abs(g_m_numerical - out.g_m) / out.g_m;

	bool pass = error < 1e-3;

	std::cout << "g_m numerical derivative: " << (pass ? "pass" : "fail");
	std::cout << " (error: " << error * 100 << "%)\n";

	return pass;
}

bool test_gds_numerical() {
	mosfet_model nmos(0.5, 1e-3);
	double v_gs = 0.8;
	double v_ds = 0.2;
	double delta = 1e-6;

	mosfet_output out = nmos.calculate(v_gs, v_ds);
	mosfet_output out_plus = nmos.calculate(v_gs, v_ds + delta);

	double g_ds_numerical = (out_plus.i_d - out.i_d) / delta;
	double error = std::abs(g_ds_numerical - out.g_ds) / out.g_ds;

	bool pass = error < 1e-3;

	std::cout << "g_ds numerical derivative: " << (pass ? "pass" : "fail");
	std::cout << " (error: " << error * 100 << "%)\n";

	return pass;
}

bool test_saturation_gds_zero() {
	mosfet_model nmos(0.5, 1e-3);
	mosfet_output out = nmos.calculate(1.0, 2.0);

	bool pass = std::abs(out.g_ds) < 1e-9;

	std::cout << "saturation g_ds = 0: " << (pass ? "pass" : "fail") << "\n";

	return pass;
}

int main() {
	std::cout << "testing small-signal parameters\n\n";

	bool all_pass = test_gm_numerical() &&
	                test_gds_numerical() &&
	                test_saturation_gds_zero();

	std::cout << "\n" << (all_pass ? "all tests passed" : "some tests failed") << "\n";

	return all_pass ? 0 : 1;
}
