#include<cstdio>

int main() {
	int n, res = 0;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			res += i + j;
		}
	}
	printf("%d", res);
}