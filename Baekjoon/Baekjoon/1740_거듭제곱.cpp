#include<cstdio>
#include<string.h>
typedef long long ll;

ll pre[63] = { 0 };
ll pre3[40] = { 0 };
ll preComb[50][50] = { { 0 },{ 1, 1 },{ 1, 2, 1 },{ 1, 3, 3, 1 },{ 1, 4 , 6, 4, 1 } };
ll res[100000] = { 0, 1, 3, 4, 9 };

ll pow(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

ll getPower(ll n) {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 3;
	else if (n == 3)
		return 4;
	else {
		if (n < 100000 && res[n] != -1)
			return res[n];
		ll ret = 0;
		int i = 0;
		while (1) {
			if (n < pre[i])
				break;
			n -= pre[i];
			++i;
		}
		if (n == 1)
			return pre3[i];
		else if (n == 0) {
			for (int k = 0; k < i; ++k)
				ret += pre3[k];
			return ret;
		}
		ret += pre3[i];
		return ret + getPower(n - 1);
	}
}

int main() {
	ll n;
	memset(res, -1, sizeof(res));

	for (int i = 0; i < 63; ++i) {
		if (i < 40)
			pre3[i] = pow(3, i);
		pre[i] = pow(2, i);
	}
	for (int i = 5; i < 45; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || i == j)
				preComb[i][j] = 1;
			else if (j == 1 || i - j == 1)
				preComb[i][j] = i;
			else
				preComb[i][j] = preComb[i - 1][j] + preComb[i - 1][j - 1];
		}
	}
	scanf("%lld", &n);
	printf("%lld", getPower(n));
}