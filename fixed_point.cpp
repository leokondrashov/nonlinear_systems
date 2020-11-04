#include <iostream>
#include <cmath>

#include "vector.h"

const double eps = 1e-5;
const double q = 0.984;

int main() {
	vector v_prev{2}, v_cur{2};
	
	v_cur[0] = 0;
	v_cur[1] = 0;

	int it_count = 0;

	vector r{2};
	r[0] = 1;
	while (r.norm1() > eps * (1 - q)) {
		it_count++;

		v_prev = v_cur;
		v_cur[0] = cos(v_prev[1]) + 0.85;
		v_cur[1] = sin(v_prev[0]) - 1.32;

		r = v_cur - v_prev;
	}

	std::cout << "x = " << v_cur[0] << ", y = " << v_cur[1] << std::endl;
	std::cout << it_count << " iterations" << std::endl;
}
