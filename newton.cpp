#include <iostream>
#include <cmath>

#include "vector.h"
#include "matrix.h"

const double eps = 1e-5;

int main() {
	vector v_prev{2}, v_cur{2};
	
	v_cur[0] = 0;
	v_cur[1] = 0;

	int it_count = 0;

	matrix f_prime{2};
	vector f{2};

	vector r{2};
	r[0] = 1;
	while (r.norm1() > eps) {
		it_count++;

		v_prev = v_cur;
		double x = v_prev[0];
		double y = v_prev[1];

		f_prime[0][0] = std::cos(x);
		f_prime[0][1] = -1;
		f_prime[1][0] = -1;
		f_prime[1][1] = -std::sin(y);

		f[0] = std::sin(x) - y - 1.32;
		f[1] = std::cos(y) - x + 0.85;

		v_cur = v_prev - f_prime.inverse() * f;

		r = v_cur - v_prev;
	}

	std::cout << "x = " << v_cur[0] << ", y = " << v_cur[1] << std::endl;
	std::cout << it_count << " iterations" << std::endl;
}
