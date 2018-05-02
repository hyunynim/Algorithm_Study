#include <cstdio>

int main() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			return 0;
		printf("%s\n", a > b ? "Yes" : "No");
	}
}