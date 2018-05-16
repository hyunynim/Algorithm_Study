#include<cstdio>

int comb[1001][1001] = { { 0 },{ 1, 1 },{ 1, 2, 1 },{ 1, 3, 3, 1 },{ 1, 4, 6, 4, 1 } };

void PreCalcComb() {
	for (int i = 5; i <= 1000; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == j || j == 0)
				comb[i][j] = 1;
			else if (i - j == 1 || j == 1)
				comb[i][j] = i;
			else
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 1000000007;
		}
	}
}

int main() {
	int n, k, t;
	PreCalcComb();
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &n, &k);
		printf("%d\n", comb[n][k]);
	}
}