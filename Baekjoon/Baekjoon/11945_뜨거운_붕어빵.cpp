#include<cstdio>

int main() {
	int n, m;
	int bbang[11][11] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%1d", &bbang[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			printf("%d", bbang[i][j]);
		}
		printf("\n");
	}

}