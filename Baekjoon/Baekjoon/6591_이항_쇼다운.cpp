#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

ll comb[1001][1001] = { { 1 },{ 1, 1 },{ 1, 2, 1 },{ 1, 3, 3, 1 },{ 1, 4, 6, 4, 1 } };

ll Comb(ll n, ll r) {
	ll res = 1;
	if (n <= 1000 && r <= 1000)
		return comb[n][r];
	for (ll i = 1; i <= r; ++i) {
		res *= n - (i - 1);
		res /= i;
	}
	return res;
}

void PreCalcComb() {
	for (int i = 5; i <= 1000; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == j || j == 0)
				comb[i][j] = 1;
			else if (i - j == 1 || j == 1)
				comb[i][j] = i;
			else {
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
				if (comb[i][j] > 2200000000LL)
					comb[i][j] = -1;
			}
		}
	}
}

int main() {
	ll n, r;
	PreCalcComb();
	while (1) {
		scanf("%lld %lld", &n, &r);
		if (n == 0 && r == 0)
			return 0;
		printf("%lld\n", Comb(n, min(r, n-r)));
	}
}

/*comment*/
//���� ���� ���ڵ��� PreCalc�� �ӵ� ���̰�
//nCr = nC(n-r) �̿��ؼ� �� �������� 
//����� INT_MAX���� ������ �׳� �� ���ϱ�� �����ֱ�