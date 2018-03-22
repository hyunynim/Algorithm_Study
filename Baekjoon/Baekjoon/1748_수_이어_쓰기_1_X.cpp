#include <stdio.h>

int pow(int a, int n) {
	int res = 1;
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
	int n, ans = 0, exp = 0;
	scanf("%d", &n);
	for (int i = 8; i >= 0; i--) {
		if (n / pow(10, i) != 0) {
			exp = i;
			break;
		}
	}
	
}