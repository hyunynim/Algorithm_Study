#include<cstdio>

int main() {
	long long n, m, res = 0;
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		res += m;
		res %= i;
	}
	printf("%lld", res + 1);
}