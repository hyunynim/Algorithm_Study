#include<cstdio>
#define MOD 1000000000
int d[234][234] = { {0}, {1, 1, 1, 1, 1}, {0, 2, 3, 4} };

int main() {
	int n, k;
	for (int i = 0; i < 201; ++i)
		d[1][i] = 1;
	for (int i = 2; i <= 200; ++i) {
		d[i][0] = 1;
		for (int j = 1; j <= 200; ++j) {
			d[i][j] = d[i][j - 1] + d[i - 1][j];
			d[i][j] %= MOD;
		}
	}
	scanf("%d %d", &n, &k);
	printf("%d", d[k][n]);
}