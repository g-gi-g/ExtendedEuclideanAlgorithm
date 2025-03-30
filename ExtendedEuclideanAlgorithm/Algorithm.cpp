#include <iostream>

struct extendedEuclideanAlgorithmResult {
	int gcd;
	int x;
	int y;
};

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

extendedEuclideanAlgorithmResult recursiveExtendedEuclideanAlgorithm(int a, int b) {
	if (b == 0) return extendedEuclideanAlgorithmResult{ a, 1, 0 };
	extendedEuclideanAlgorithmResult res = recursiveExtendedEuclideanAlgorithm(b, a%b);
	int x = res.y;
	int y = res.x - (a / b) * res.y;
	return extendedEuclideanAlgorithmResult{ res.gcd, x, y };
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
	//std::cout << inverseElement(a, b) << std::endl;
	extendedEuclideanAlgorithmResult res = recursiveExtendedEuclideanAlgorithm(a, b);
	std::cout << "gcd = " << res.gcd << " x = " << res.x << " y = " << res.y;
	return 0;
}