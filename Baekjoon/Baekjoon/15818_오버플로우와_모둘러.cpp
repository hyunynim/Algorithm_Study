#include<cstdio>

int main() {
	long long n, m, res = 1, tmp;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &tmp);
		res *= (tmp%m);
		res %= m;
	}
	printf("%lld", res);
}