#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace phys {
	const double q = 1.602e-19;
	const double k_b = 1.381e-23;
	const double eps_0 = 8.854e-12;
	const double eps_si = 11.7 * eps_0;
	const double eps_ox = 3.9 * eps_0;
	const double T_nom = 300.15;
	const double V_t = k_b * T_nom / q;
}

#endif
