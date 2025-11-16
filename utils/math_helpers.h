#ifndef MATH_HELPERS_H
#define MATH_HELPERS_H

#include <cmath>
#include <algorithm>

namespace math_util {
	inline double smooth_max(double a, double b, double alpha = 1e-3) {
		return std::log(std::exp(a / alpha) + std::exp(b / alpha)) * alpha;
	}

	inline double smooth_min(double a, double b, double alpha = 1e-3) {
		return -smooth_max(-a, -b, alpha);
	}

	inline double clamp(double val, double lo, double hi) {
		return std::max(lo, std::min(val, hi));
	}
}

#endif
