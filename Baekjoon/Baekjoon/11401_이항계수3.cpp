#include <stdio.h>
long long int mul(long long x, long long y, long long p) {
	long long int ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}
int main() {
	long long int n, r, p;
	scanf("%lld %lld", n, r);
	p = 1000000007LL;
	long long int ans = 1, t1 = 1, t2 = 1; \
		for (long long int i = 1; i <= n; i++) {
			t1 *= i;
			t1 %= p;
		}
	for (long long int i = 1; i <= r; i++) {
		t2 *= i;
		t2 %= p;
	}
	for (long long int i = 1; i <= n - r; i++) {
		t2 *= i;
		t2 %= p;
	}
	long long int t3 = mul(t2, p - 2, p);
	t3 %= p;
	ans = t1*t3;
	ans %= p;
	printf("%lld", ans);
	return 0;
}