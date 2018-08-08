#include<cstdio>
typedef long long ll;
int main() {
	int t = 0;
	scanf("%d", &t);
	ll sum[305] = { 0 };
	for (int i = 1; i < 305; ++i)
		sum[i] = sum[i - 1] + i;
	for (int TC = 0; TC<t; ++TC)
	{
		int n;
		scanf("%d", &n);
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += i * sum[i + 1];
		}
		printf("%lld\n", ans);
	}
}