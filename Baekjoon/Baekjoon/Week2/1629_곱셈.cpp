#include <stdio.h>

long long pow(long long a, long long b, long long c) {
	long long res = 1;
	while (b > 0) {
		if (b % 2 != 0) {
			res *= a;
			res %= c;
		}
		a *= a;
		a %= c;
		b /= 2;
	}
	return res;
}

int main()
{
	long long int a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c );
	printf("%lld", pow(a, b, c));
}