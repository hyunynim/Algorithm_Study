#include <stdio.h>

long long int sigma1(int n);
long long int sigma2(long long int n);

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld\n", sigma2(n));
	return 0;
}

long long int sigma1(int n)
{
	long long int res = 0;
	for (int i = 1; i <= n; i++)
		res += i;
	return res;
}

long long int sigma2(long long int n)
{
	long long int res = n*(n + 1) / 2;
	return res;
}