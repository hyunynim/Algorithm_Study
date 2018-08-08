#include<cstdio>
typedef long long ll;

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", (a + b)*(a - b));
}