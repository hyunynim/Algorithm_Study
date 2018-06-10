#include<cstdio>
#include<string.h>
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		int n, m, res = 0;
		bool grid[101][101] = { 0 };
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				scanf("%d", &grid[i][j]);
		}
		for (int i = 0; i < m; ++i) {
			int cnt = 0;
			for (int j = n - 1; j >= 0; --j) {
				if (grid[j][i]) {
					res += (n - 1) - j - cnt;
					++cnt;
				}
			}
		}
		printf("%d\n", res);
	}
}