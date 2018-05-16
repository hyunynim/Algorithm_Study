#include<cstdio>

int main() {
	int a, b, c, n;
	scanf("%d %d %d %d", &a, &b, &c, &n);
	for (int i = 0; a*i <= n; ++i) {
		for (int j = 0; a*j <= n; ++j) {
			for (int k = 0; a*k <= n; ++k) {
				if (a*i + b*j + c*k == n) {
					printf("1");
					return 0;
				}
			}
		}
	}
	printf("0");
}