#include "../models/square_law/mos_model.h"
#include <iostream>
#include <iomanip>

int main() {
	double v_th = 0.5;
	double k_ref = 1e-3;
	double k_out = 1e-3;

	mosfet_model m_ref(v_th, k_ref);
	mosfet_model m_out(v_th, k_out);

	double i_ref = 100e-6;
	double v_dd = 3.0;

	double v_gs = v_th + std::sqrt(2.0 * i_ref / k_ref);

	double v_ds_ref = v_gs;
	double v_ds_out = v_dd;

	mosfet_output out_ref = m_ref.calculate(v_gs, v_ds_ref);
	mosfet_output out_out = m_out.calculate(v_gs, v_ds_out);

	double mismatch = (out_out.i_d - i_ref) / i_ref * 100.0;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "current mirror analysis\n\n";
	std::cout << "parameters:\n";
	std::cout << "  i_ref = " << i_ref * 1e6 << " ua\n";
	std::cout << "  k_ref = " << k_ref << " a/v^2\n";
	std::cout << "  k_out = " << k_out << " a/v^2\n\n";

	std::cout << "operating point:\n";
	std::cout << "  v_gs = " << v_gs << " v\n";
	std::cout << "  v_ds_ref = " << v_ds_ref << " v\n";
	std::cout << "  v_ds_out = " << v_ds_out << " v\n\n";

	std::cout << "currents:\n";
	std::cout << "  i_ref = " << out_ref.i_d * 1e6 << " ua\n";
	std::cout << "  i_out = " << out_out.i_d * 1e6 << " ua\n";
	std::cout << "  mismatch = " << mismatch << " %\n";

	return 0;
}
