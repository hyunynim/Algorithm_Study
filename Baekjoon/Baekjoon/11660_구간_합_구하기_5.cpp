#include<cstdio>

int sum[1025][1025];
int num[1025][1025];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &num[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num[i][j];
		}
	}
	int a, b, c, d;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", sum[c][d] - sum[a -1 ][d] - sum[c][b - 1] + sum[a-1][b-1]);
	}
}