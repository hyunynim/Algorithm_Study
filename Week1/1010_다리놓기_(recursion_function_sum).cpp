#include <stdio.h>

int comb(int n, int m);

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
	if (n == 0 || m == 0 || n == m)
		return 1;
	else if (m == 1 || n - m == 1)
		return n;
	else
		return comb(n - 1, m - 1) + comb(n - 1, m);
}