#include<cstdio>
#include<cmath>
typedef long long ll;
int main() {
	ll pow[16] = { 1, 4 };
	ll ans[123] = { 4, 9 };

	for (int i = 2; i < 16; ++i) {
		pow[i] = pow[i - 1] * 4;
		ans[i] = pow[i - 1] * 3 + sqrt(pow[i - 1]) * 2 + ans[i - 1];
	}
	int n;
	scanf("%d", &n);
	printf("%d", ans[n]);
}