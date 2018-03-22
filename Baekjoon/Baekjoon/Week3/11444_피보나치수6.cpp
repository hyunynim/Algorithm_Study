#include <stdio.h>
long long m = 1000000007LL;

long long pow_matrix(long long fib[2][2], long long n) {
	long long res[2][2] = { 1LL,1LL,1LL,0LL }, tmp[2][2];
	while (n > 0) {
		if (n % 2 != 0) {
			tmp[0][0] = ((fib[0][0] * res[0][0]) % m + (fib[0][1] * res[1][0]) % m) % m;
			tmp[1][0] = ((fib[1][0] * res[0][0]) % m + (fib[1][1] * res[1][0]) % m) % m;
			tmp[0][1] = tmp[1][0];
			tmp[1][1] = ((fib[1][0] * res[0][1]) % m + (fib[1][1] * res[1][1]) % m) % m;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++)
					res[i][j] = tmp[i][j];
			}
		}
		tmp[0][0] = ((fib[0][0] * fib[0][0]) % m + (fib[0][1] * fib[1][0]) % m) % m;
		tmp[1][0] = ((fib[1][0] * fib[0][0]) % m + (fib[1][1] * fib[1][0]) % m) % m;
		tmp[0][1] = tmp[1][0];
		tmp[1][1] = ((fib[1][0] * fib[0][1]) % m + (fib[1][1] * fib[1][1]) % m) % m;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++)
				fib[i][j] = tmp[i][j];
		}
		n /= 2;
	}
	return res[1][0];
}

int main() {
	long long fib[2][2] = { 1LL, 1LL, 1LL, 0LL };
	long long n;
	scanf("%lld", &n);
	printf("%lld", pow_matrix(fib, n-1));
	return 0;
}