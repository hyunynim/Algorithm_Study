#include <stdio.h>

long long calc(long long n) {
	if (n % 2 == 0)
		return n / 2;
	else
		return 3 * n + 1;
}

int main() {
	long long n;
	scanf("%lld", &n);
	int cnt = 1;
	while (n != 1) {
		n = calc(n);
		cnt++;
	}
	printf("%d", cnt);
}