#include <stdio.h>

int co[1000][1000] = { {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}, {1, 5, 10, 10, 5, 1}, {1, 6, 15, 20, 15, 6, 1} };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 5; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j > i)
				break;
			else {
				if (j == 0)
					co[i][j] = 1;
				else if (j == 1 || i - j == 1)
					co[i][j] = i;
				else
					co[i][j] = (co[i - 1][j - 1] + co[i - 1][j])%10007;
			}
		}
	}
	printf("%d\n", co[n][m]);
	return 0;
}
