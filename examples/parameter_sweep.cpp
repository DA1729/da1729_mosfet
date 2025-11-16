#include "../models/square_law/mos_model.h"
#include "../utils/csv_writer.h"
#include <iostream>

int main() {
	double v_th = 0.5;
	double k = 1e-3;

	mosfet_model nmos(v_th, k);

	csv_writer writer("parameter_sweep.csv");
	writer.write_header({"v_gs", "v_ds", "i_d", "g_m", "g_ds"});

	for (double v_gs = 0.0; v_gs <= 2.0; v_gs += 0.1) {
		for (double v_ds = 0.0; v_ds <= 2.0; v_ds += 0.1) {
			mosfet_output out = nmos.calculate(v_gs, v_ds);
			writer.write_row({v_gs, v_ds, out.i_d, out.g_m, out.g_ds});
		}
	}

	std::cout << "parameter sweep completed: parameter_sweep.csv\n";

	return 0;
}
