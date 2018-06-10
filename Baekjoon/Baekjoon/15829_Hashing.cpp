#include<cstdio>

typedef long long ll;
ll r[51] = { 0 };
ll MOD = 1234567891LL;

ll pow(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2) {
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		n /= 2;
	}
	return res;
}

int main() {
	for (int i = 0; i < 51; ++i)
		r[i] = pow(31, i);
	int n;
	char msg[123];
	scanf("%d %s", &n, msg);
	
	ll res = 0;
	for (int i = 0; msg[i] != '\0'; ++i) {
		res += ((msg[i] - 'a' + 1) * r[i]) % MOD;
		res %= MOD;
	}
	printf("%lld", res);
}