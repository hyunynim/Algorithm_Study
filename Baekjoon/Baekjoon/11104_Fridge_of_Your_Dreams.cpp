#include<cstdio>
typedef long long ll;

ll pow(ll a, ll n) {
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
	ll pow2[25] = { 0 };
	for (int i = 0; i < 25; ++i)
		pow2[i] = pow(2, i);

	char msg[1233];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		ll res = 0;
		for (int j = 0; j < 24; ++j)
			res += msg[j] == '0' ? 0 : pow2[23 - j];
		printf("%lld\n", res);
	}
}