#include <iostream>

typedef long long ll;
const ll p = 1000000007LL;
ll fac[4000001] = { 1 };

ll pow(ll x, ll y)
{
	ll r = 1;
	while (y > 0) {
		if (y % 2) {
			r *= x;
			r %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return r;
}

ll comb(ll n, ll k)
{
	ll nf = 1, a = 1;

	nf = fac[n];
	a = (fac[k] * fac[n - k]) % p;

	return (nf*pow(a, p - 2)) % p;


}

int main(void)
{
	for (int i = 1; i <= 4000000; ++i)
		fac[i] = (fac[i - 1] * i) % p;
	ll n, k;
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%lld %lld", &n, &k);
		printf("%lld\n", comb(n, k));
	}
	return 0;
}
