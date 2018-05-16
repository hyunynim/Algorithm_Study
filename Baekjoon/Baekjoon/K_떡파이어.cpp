#include<cstdio>
typedef long long ll;


ll powMod(ll a, ll n, ll m) {
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n /= 2;
	}
	return res;
}

int main() {
	ll n;
	scanf("%lld", &n);
	printf("%lld", powMod(2LL, n-1, 1000000007LL));
}