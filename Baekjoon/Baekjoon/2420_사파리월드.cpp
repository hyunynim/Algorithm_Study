#include<cstdio>
typedef long long ll;
ll ABS(ll a) {
	return a > 0 ? a : -a;
}

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld", ABS(n - m));
}