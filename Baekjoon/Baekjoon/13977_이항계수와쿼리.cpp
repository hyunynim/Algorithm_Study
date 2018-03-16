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
	int m;
	p = 1000000007LL;

	scanf("%d", &m);
	for (int ind = 0; ind < m; ind++) {
		scanf("%lld %lld", &n, &r);
		long long int ans = 1, t1 = 1, t2 = 1;
		for (long long int i = n; i >= n - r + 1; i--) {
			t1 *= i;
			t1 %= p;
		}
		for (long long int i = 1; i <= r; i++) {
			t2 *= i;
			t2 %= p;
		}
		long long int t3 = mul(t2, p - 2, p);
		t3 %= p;
		ans = t1*t3;
		ans %= p;
		printf("%lld\n", ans);
	}
	return 0;
}