#include<cstdio>

void swap(long long *a, long long * b)
{
	if (*a > *b) {
		long long tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	swap(&a, &b);
	if (a == b || b - 1 == a) {
		printf("0");
		return 0;
	}
	printf("%lld\n", b - a - 1);
	for (long long i = a + 1; i < b - 1; ++i)
		printf("%lld ", i);
	printf("%lld", b - 1);
}