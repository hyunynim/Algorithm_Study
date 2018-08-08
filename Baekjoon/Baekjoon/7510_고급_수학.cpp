#include<cstdio>

bool isOr(int a, int b, int c) {
	return a * a + b * b == c * c
		|| a * a + c * c == b * b
		|| b * b + c * c == a * a;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("Scenario #%d:\n", i + 1);
		if (isOr(a, b, c))
			printf("yes\n\n");
		else
			printf("no\n\n");
	}
}