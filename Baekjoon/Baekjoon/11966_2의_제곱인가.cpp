#include <iostream>

unsigned int pow(int a, int n) {
	unsigned int res = 1;
	while (n > 0) {
		if (n % 2 == 1)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

int main() {
	unsigned int n;
	scanf("%u", &n);
	for (int i = 0; i < 31; ++i) {
		if (pow(2, i) == n) {
			printf("1");
			return 0;
		}
	}
	printf("0");
}