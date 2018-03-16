#include <stdio.h>

int main() {
	int t, n, m, res[31][31];
	for (int i = 0; i <= 30; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			if (i < j)
				break;

			if (j == 0 || i == j)
				res[i][j] = 1;

			else if (i - j == 1 || j == 1)
				res[i][j] = i;
			else
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &m, &n);
		printf("%d", res[n][m]);
	}
	return 0;
}