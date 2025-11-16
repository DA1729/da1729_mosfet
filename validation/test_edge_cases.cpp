#include "../models/square_law/mos_model.h"
#include <iostream>
#include <cmath>

bool test_vgs_at_threshold() {
	mosfet_model nmos(0.5, 1e-3);
	mosfet_output out = nmos.calculate(0.5, 1.0);

	bool pass = std::abs(out.i_d) < 1e-9;

	std::cout << "v_gs = v_th: " << (pass ? "pass" : "fail") << "\n";

	return pass;
}

bool test_vds_zero() {
	mosfet_model nmos(0.5, 1e-3);
	mosfet_output out = nmos.calculate(1.0, 0.0);

	bool pass = std::abs(out.i_d) < 1e-9;

	std::cout << "v_ds = 0: " << (pass ? "pass" : "fail") << "\n";

	return pass;
}

bool test_negative_vgs() {
	mosfet_model nmos(0.5, 1e-3);
	mosfet_output out = nmos.calculate(-0.5, 1.0);

	bool pass = std::abs(out.i_d) < 1e-9 &&
	            std::abs(out.g_m) < 1e-9 &&
	            std::abs(out.g_ds) < 1e-9;

	std::cout << "negative v_gs: " << (pass ? "pass" : "fail") << "\n";

	return pass;
}

bool test_triode_saturation_boundary() {
	mosfet_model nmos(0.5, 1e-3);
	double v_gs = 1.0;
	double v_ov = v_gs - 0.5;
	double v_ds = v_ov;

	mosfet_output out_triode = nmos.calculate(v_gs, v_ds - 1e-6);
	mosfet_output out_sat = nmos.calculate(v_gs, v_ds + 1e-6);

	bool continuous = std::abs(out_triode.i_d - out_sat.i_d) < 1e-6;

	std::cout << "triode-saturation boundary: " << (continuous ? "pass" : "fail") << "\n";

	return continuous;
}

bool test_high_voltage() {
	mosfet_model nmos(0.5, 1e-3);
	mosfet_output out = nmos.calculate(5.0, 5.0);

	bool pass = std::isfinite(out.i_d) &&
	            std::isfinite(out.g_m) &&
	            std::isfinite(out.g_ds);

	std::cout << "high voltage stability: " << (pass ? "pass" : "fail") << "\n";

	return pass;
}

int main() {
	std::cout << "testing edge cases\n\n";

	bool all_pass = test_vgs_at_threshold() &&
	                test_vds_zero() &&
	                test_negative_vgs() &&
	                test_triode_saturation_boundary() &&
	                test_high_voltage();

	std::cout << "\n" << (all_pass ? "all tests passed" : "some tests failed") << "\n";

	return all_pass ? 0 : 1;
}
