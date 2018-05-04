#include<cstdio>

int main() {
	int n, m;
	int cnt[100001] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		cnt[a]++;
		cnt[b]++;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d\n", cnt[i]);
}