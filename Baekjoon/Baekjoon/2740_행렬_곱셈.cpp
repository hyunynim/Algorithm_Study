#include<cstdio>

int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	int ** matrix1 = new int *[n];
	for (int i = 0; i < n; ++i) {
		matrix1[i] = new int[m];
		for (int j = 0; j < m; ++j)
			scanf("%d", &matrix1[i][j]);
	}
	scanf("%d %d", &m, &k);
	int ** matrix2 = new int *[m];
	int ** matrix3 = new int *[n];
	for (int i = 0; i < m; ++i) {
		matrix2[i] = new int[k];
		for (int j = 0; j < k; ++j)
			scanf("%d", &matrix2[i][j]);
	}
	
	for (int i = 0; i < n; ++i) {
		matrix3[i] = new int[k];
		for (int j = 0; j < k; ++j) {
			matrix3[i][j] = 0;
			for (int a = 0; a < m; ++a) {
				matrix3[i][j] += matrix1[i][a] * matrix2[a][j];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			printf("%d ", matrix3[i][j]);
		}
		printf("\n");
	}
}