#include<cstdio>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, k, candy, ans = 0;
		scanf("%d %d", &n, &k);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &candy);
			ans += candy / k;
		}
		printf("%d\n", ans);
	}
}