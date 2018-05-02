#include <iostream>

int cache[1001][10] = { {0}, {10, 9, 8, 7, 6, 5, 4, 3, 2, 1} };


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0+j; k < 10; ++k) {
				cache[i][j] += cache[i - 1][k];
				cache[i][j] %= 10007;
			}
		}
	}
	printf("%d", cache[n][0]);
}