#include <stdio.h>

int main() {
	int n, res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		res += b%a;
	}
	printf("%d", res);
}