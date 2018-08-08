#include<cstdio>
#define VMAX 123
#define INF 1e9
typedef long long ll;
int D[VMAX][VMAX];
int P[VMAX][VMAX];
int W[VMAX][VMAX];
void Floyd() {

	int i, j, k;
	for (i = 0; i < VMAX; i++)	// 배열 초기화 
		for (j = 0; j < VMAX; j++) {
			P[i][j] = -1;
			D[i][j] = W[i][j];
		}

	for (k = 0; k < VMAX; k++) {
		for (i = 0; i < VMAX; i++) {
			for (j = 0; j < VMAX; j++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;
				}
			}
		}
	}
}
int main() {
	int n, m;
	int a, b, w;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < VMAX; ++i) {
		for (int j = 0; j < VMAX; ++j) {
			W[i][j] = INF;
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		W[a][b] = w;
	}
	Floyd();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
}