#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;

ll pow(ll a, int n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

int main() {
	ll pow5[27];
	ll pow2[63];
	for (int i = 0; i < 63; ++i) {
		if (i < 27)
			pow5[i] = pow(5, i);
		pow2[i] = pow(2, i);
	}
	int n, m;
	scanf("%d %d", &n, &m);
	ll ans[2][2] = { 0 };
	for (int i = 1; i < 63; ++i) {
		if (i < 27) {
			ans[0][1] += n / pow5[i];
			ans[1][1] += (n - m) / pow5[i];
			ans[1][1] += m / pow5[i];
		}
		ans[0][0] += n / pow2[i];
		ans[1][0] += (n - m) / pow2[i];
		ans[1][0] += m / pow2[i];
	}
		ans[0][0] -= ans[1][0];
		ans[0][1] -= ans[1][1];
		printf("%lld", min(ans[0][0], ans[0][1]));
}