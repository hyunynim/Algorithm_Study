#include<cstdio>
#define MOD 14579LL
typedef long long ll;
int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);

	ll res = 1, tmp;
	for (int i = a; i <= b; ++i) {
		tmp = i*(i + 1) / 2;
		res *= (tmp%MOD);
		res %= MOD;
	}
	printf("%lld", res);
}