#include<cstdio>

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	int res = 0;
	int i;
	for (i = 1; i <= m; ++i)
		res += m % i;
	res += res * (n / m - 1);
	n %= m;

	res += m*n;
	printf("%lld", res);
}