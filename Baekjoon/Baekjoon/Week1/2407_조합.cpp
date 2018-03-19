#include <stdio.h>

long long int co1[101][101] = { {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1} };
long long int co2[101][101] = { 0 };

long long int pow10(int n) {
	long long res = 1, pow = 10;
	
		while (n > 0) {
			if (n % 2 != 0) {
				res *= pow;
			}
			pow *= pow;
			n /= 2;
		}
		return res;
	
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 3; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j > i)
				break;
			else {
				if (j == 1 || i - j == 1)
					co1[i][j] = i;
				else if (j == 0)
					co1[i][j] = 1;
				else {
					co1[i][j] = co1[i - 1][j - 1] + co1[i - 1][j];
					co2[i][j] = co2[i - 1][j - 1] + co2[i - 1][j];
					if (co1[i][j] > pow10(15))
					{
						co2[i][j] += co1[i][j] / pow10(15);
						co1[i][j] %= pow10(15);
					}
				}
			}
		}
	}
	if (co2[n][m] != 0)
	{
		printf("%lld", co2[n][m]);
		for (int i = 14; i > 0; i--) {
			if (co1[n][m] / pow10(i) == 0)
				printf("0");
			else
				break;
		}
	}
	printf("%lld", co1[n][m]);
	return 0;
}