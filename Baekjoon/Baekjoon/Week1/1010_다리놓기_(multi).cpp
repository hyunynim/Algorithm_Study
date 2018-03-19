#include <stdio.h>

int comb(int n, int m);
int calc(int n, int m) {
	return n - m > m ? n - m : m;
}


int main() {
	int t, n, m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &m, &n);
		printf("%d\n", comb(n, m));
	}
	return 0;
}

int comb(int n, int m)
{
	double res = 1;
	if (n == 0 || m == 0 || n == m)
		return 1;
	else if (m == 1 || n - m == 1)
		return n;
	else
	{
		for (int i = 0; i < n - m; i++)
			res = res * (double)(n - i) / (double)(i + 1);

		return (int)res;
	}
}