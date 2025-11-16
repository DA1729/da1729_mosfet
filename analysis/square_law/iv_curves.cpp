#include "../models/square_law/mos_model.h"
#include "../utils/csv_writer.h"
#include <iostream>

int main() {
	double v_th = 0.5;
	double k = 1e-3;

	mosfet_model nmos(v_th, k);

	csv_writer writer("iv_curves.csv");
	writer.write_header({"v_ds", "v_gs", "i_d"});

	double v_gs_values[] = {0.6, 0.8, 1.0, 1.2, 1.5};
	int n_curves = 5;

	for (int i = 0; i < n_curves; ++i) {
		double v_gs = v_gs_values[i];
		for (double v_ds = 0.0; v_ds <= 3.0; v_ds += 0.01) {
			mosfet_output out = nmos.calculate(v_gs, v_ds);
			writer.write_row({v_ds, v_gs, out.i_d});
		}
	}

	std::cout << "iv curves generated: iv_curves.csv\n";
	std::cout << "curves for v_gs = 0.6, 0.8, 1.0, 1.2, 1.5 v\n";

	return 0;
}
