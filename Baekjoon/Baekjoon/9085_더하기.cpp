#include<cstdio>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, res = 0, tmp;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			res += tmp;
		}
		printf("%d\n", res);
	}
}