#include<cstdio>

typedef long long ll;
ll comb[50][50] = { { 1 },{ 1, 1 },{ 1, 2, 1 },{ 1, 3, 3, 1 },{ 1, 4, 6, 4, 1 } };

ll GetSum(int start, int finish, int line, int toPick) {
	ll res = 0;
	for (int i = start; i <= finish; ++i)
		res += comb[line][i];
	if (toPick == 0) 
		return res;
	
	else 
		return GetSum(start, finish + 1, line + 1, toPick - 1) + res;
	
}

int main() {
	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);
	for (int i = 5; i < 50; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == j || j == 0)
				comb[i][j] = 1;
			else if (i - j == 1 || j == 1)
				comb[i][j] = i;
			else
				comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
	ll res = GetSum(c - 1, c - 1, r - 1, w - 1);
	printf("%lld", res);

}