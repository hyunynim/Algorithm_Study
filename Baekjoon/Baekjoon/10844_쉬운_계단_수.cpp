#include <iostream>
#define M 1000000000
long long cache[101][11] = { {0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9} };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0)
				cache[i][j] = cache[i - 1][1];
			else if (j == 9)
				cache[i][j] = cache[i - 1][8];
			else
				cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1])%M;
			cache[i][10] += cache[i][j];
			cache[i][10] %= M;
		}
	}
	printf("%lld", cache[n][10]);
}