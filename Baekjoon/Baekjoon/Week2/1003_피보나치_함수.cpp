#include <stdio.h>

long long int res[50] = { 0, 1, 1, 2, 3, 5, 8 };

long long int fib(int n) {
	if (n != 0 && res[n] == 0) {
		res[n] = fib(n - 1) + fib(n - 2);
	}
	return res[n];
}

int main()
{
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		if (n == 0)
			printf("1 0\n");
		else if (n == 1)
			printf("0 1\n");
		else
			printf("%lld %lld\n", fib(n - 1), fib(n));
	}
	return 0;
}