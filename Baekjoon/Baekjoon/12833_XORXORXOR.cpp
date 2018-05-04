#include<cstdio>

int main() {
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	if (a == b) {
		printf("0");
		return 0;
	}
	if (c % 2 == 0)
		printf("%lld", a);
	else
		printf("%lld", a^b);
}