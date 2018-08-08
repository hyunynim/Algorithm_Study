#include<cstdio>
typedef long long ll;
ll pow5[20];

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
	int n, ans = 0;
	ll pow5[27];
	for (int i = 0; i < 27; ++i)
		pow5[i] = pow(5, i);
	
	scanf("%d", &n);
	for (int i = 1; i < 27; ++i)
		ans += n / pow5[i];
	printf("%d", ans);
}