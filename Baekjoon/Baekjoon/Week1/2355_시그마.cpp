#include <stdio.h>

void max_(long long int * a, long long int * b) {
	long long int temp;
	if (*a > *b) {
		temp = *b;
		*b = *a;
		*a = temp;
	}
}

long long int calc(long long int a, long long int b);

int main()
{
	long long int a, b, res;
	scanf("%lld %lld", &a, &b);
	max_(&a, &b);
	res = calc(a, b);
	printf("%lld\n", res);
}

long long int calc(long long int a, long long int b)
{
	if (b <= 0)
		return -(((-a)*(-a + 1) / 2) + -((-b)*(-b - 1) / 2));
	else if (a <= 0)
		return -(((-a)*(-a + 1) / 2)) + (b)*(b + 1) / 2;
	else
		return (b)*(b + 1) / 2 - (a)*(a - 1) / 2;
}