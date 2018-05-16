#include<cstdio>

int ABS(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x1, y1, h1, x2, y2, h2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &h1, &x2, &y2, &h2);
		printf("%d\n", ABS(x1 - x2) + ABS(y1 - y2) + h1 + h2);
	}
}