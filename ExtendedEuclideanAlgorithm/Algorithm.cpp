#include <iostream>

int inverseElement(int a, int m) {
	if (a == 0) {
		return -1;
	}
	int y0 = 0;
	int y1 = 1;
	int q, tmp;
	int b = m;
	while (a != m) {
		if (a == 1 || m == 1) {
			int res = y1 % b;
			if (res < 0) {
				return res + b;
			}
			return res;
		}
		if (a == 0) {
			return -1;
		}
		else if (m == 0) {
			return -1;
		}
		if (a > m) {
			q = a / m;
			a %= m;
		}
		else {
			q = m / a;
			m %= a;
		}
		tmp = y1;
		y1 = y0 - y1 * q;
		y0 = tmp;
	}
	int res = y1 % b;
	if (res < 0) {
		return res + b;
	}
	return res;
}

int gcd(int a, int b) {
	while (a != b) {
		if (a == 0) {
			return b;
		}
		else if (b == 0) {
			return a;
		}
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << inverseElement(a, b) << std::endl;
	return 0;
}