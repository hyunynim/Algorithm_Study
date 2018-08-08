#include<cstdio>
int sum[123456];

int main() {
	int n, m, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		sum[i] = i == 0 ? a : sum[i - 1] + a;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a; --b;
		printf("%d\n", a > 0 ? sum[b] - sum[a - 1] : sum[b]);
	}
}