#include<cstdio>
typedef long long ll;

ll pow(int a, int n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}
ll comb[101][101] = { { 0 },{ 1, 1 },{ 1, 2, 1 },{ 1, 3, 3, 1 },{ 1, 4, 6, 4, 1 } };

void PreCalcComb() {
	for (int i = 5; i <= 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == j || j == 0)
				comb[i][j] = 1;
			else if (i - j == 1 || j == 1)
				comb[i][j] = i;
			else
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
		}
	}
}
int main() {
	ll k, n;
	PreCalcComb();
	scanf("%lld %lld", &k, &n);
	ll res = pow(2, n);
	for (int i = k; i <= n; ++i) {
		res -= pow(2, n - i) * comb[i - 1][2];
	}
	printf("%lld", res);
}