#include<cstdio>
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", (a / b)*(a / b));
	}
}