#include <stdio.h>

long long int fib[100000] = { 0, 1, 1, 2, 3, 5, 8, 13 };

long long int fibo(int n) {
	if (n != 0 && fib[n] == 0) {
		fib[n] = fibo(n - 1) + fibo(n - 2);
	}
	return fib[n];
}

long long int fibo_re(int n) {
	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	else
		return fibo_re(n - 1) + fibo_re(n - 2);

}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld\n", fibo(n));
	return 0;
}