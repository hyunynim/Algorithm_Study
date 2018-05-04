#include<cstdio>
typedef long long ll;
ll m = 1000000007LL;
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
	int n;
	scanf("%d", &n);
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		res += ((a*b) % m)*powMod(2, b - 1, m) % m;
		res %= m;
	}
	printf("%lld", res);
}

/*comment*/
//argument를 ll로 안해놓고 res %= m을 빼먹음
//틀림
//디버깅용 출력코드 안빼먹고 계속 제출함;;; 