#include <stdio.h>

unsigned long long pow(int a, int n) {
	unsigned long long res = 1;
	while (n > 0) {
		if (n % 2 != 0) {
			res *= a;
		}
		a *= a;
		n /= 2;
	}
	return res;
}
int main() {
	int MAX = 4611686018427387904LL;
	for (int i = 43; i < 2000000000; i = i + 43) {
		printf("%d \n", i % 25);
	}
}