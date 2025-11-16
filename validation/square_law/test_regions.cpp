#include "../models/square_law/mos_model.h"
#include <iostream>
#include <iomanip>
#include <cmath>

bool test_cutoff() {
	mosfet_model nmos(0.5, 1e-3);
	mosfet_output out = nmos.calculate(0.3, 1.0);

	bool pass = (std::abs(out.i_d) < 1e-9) &&
	            (std::abs(out.g_m) < 1e-9) &&
	            (std::abs(out.g_ds) < 1e-9);

	std::cout << "cutoff region: " << (pass ? "pass" : "fail") << "\n";
	return pass;
}

bool test_triode() {
	mosfet_model nmos(0.5, 1e-3);
	double v_gs = 1.0;
	double v_ds = 0.2;
	mosfet_output out = nmos.calculate(v_gs, v_ds);

	double v_ov = v_gs - 0.5;
	double i_d_expected = 1e-3 * (v_ov * v_ds - 0.5 * v_ds * v_ds);
	double g_m_expected = 1e-3 * v_ds;
	double g_ds_expected = 1e-3 * (v_ov - v_ds);

	bool pass = (std::abs(out.i_d - i_d_expected) < 1e-9) &&
	            (std::abs(out.g_m - g_m_expected) < 1e-9) &&
	            (std::abs(out.g_ds - g_ds_expected) < 1e-9);

	std::cout << "triode region: " << (pass ? "pass" : "fail") << "\n";
	return pass;
}

bool test_saturation() {
	mosfet_model nmos(0.5, 1e-3);
	double v_gs = 1.0;
	double v_ds = 2.0;
	mosfet_output out = nmos.calculate(v_gs, v_ds);

	double v_ov = v_gs - 0.5;
	double i_d_expected = 0.5 * 1e-3 * v_ov * v_ov;
	double g_m_expected = 1e-3 * v_ov;

	bool pass = (std::abs(out.i_d - i_d_expected) < 1e-9) &&
	            (std::abs(out.g_m - g_m_expected) < 1e-9) &&
	            (std::abs(out.g_ds) < 1e-9);

	std::cout << "saturation region: " << (pass ? "pass" : "fail") << "\n";
	return pass;
}

int main() {
	std::cout << "testing operating regions\n\n";

	bool all_pass = test_cutoff() && test_triode() && test_saturation();

	std::cout << "\n" << (all_pass ? "all tests passed" : "some tests failed") << "\n";

	return all_pass ? 0 : 1;
}
