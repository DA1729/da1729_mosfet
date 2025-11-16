#include "../models/square_law/mos_model.h"
#include "../utils/csv_writer.h"
#include <iostream>

int main() {
	double v_th = 0.5;
	double k = 1e-3;

	mosfet_model nmos(v_th, k);

	csv_writer writer("gm_vs_vgs.csv");
	writer.write_header({"v_gs", "v_ds", "g_m", "g_ds"});

	double v_ds_values[] = {0.5, 1.0, 1.5, 2.0};
	int n_curves = 4;

	for (int i = 0; i < n_curves; ++i) {
		double v_ds = v_ds_values[i];
		for (double v_gs = 0.0; v_gs <= 2.0; v_gs += 0.01) {
			mosfet_output out = nmos.calculate(v_gs, v_ds);
			writer.write_row({v_gs, v_ds, out.g_m, out.g_ds});
		}
	}

	std::cout << "g_m vs v_gs generated: gm_vs_vgs.csv\n";
	std::cout << "curves for v_ds = 0.5, 1.0, 1.5, 2.0 v\n";

	return 0;
}
