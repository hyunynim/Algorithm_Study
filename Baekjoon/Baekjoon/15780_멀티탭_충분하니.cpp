#include<cstdio>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int tmp;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &tmp);
		n -= (tmp / 2 + tmp % 2);
	}
	printf("%s", n > 0 ? "NO" : "YES");
}