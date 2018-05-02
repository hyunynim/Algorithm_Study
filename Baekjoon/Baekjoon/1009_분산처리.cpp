#include <iostream>


int powMod(int a, int b, int m) {
	int res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		b /= 2;
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		int res = powMod(a, b, 10);
		printf("%d\n", res == 0 ? 10 : res);
	}
}