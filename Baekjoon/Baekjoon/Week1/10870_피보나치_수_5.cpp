#include <stdio.h>

long long int num[91] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };

long long int fib(int n) {
	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	else if (num[n] == 0)
		num[n] = fib(n - 1) + fib(n - 2);
	return num[n];
}

long long int fib2(int n) {
	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

long long int fib3(int n) {
	long long int res = 0, n_1 = 1, n_2 = 1;
	if (n == 1 || n == 2)
		return 1;
	else {
		for (int i = 0; i < n - 2; i++) {
			res = n_1 + n_2;
			n_1 = n_2;
			n_2 = res;
		}
		return res;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", fib3(n));
	return 0;
}