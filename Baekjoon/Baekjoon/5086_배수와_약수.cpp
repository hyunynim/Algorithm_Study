#include <cstdio>

int main() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (!a & !b)
			return 0;
		if (a % b == 0)
			printf("multiple\n");
		else if (b%a == 0)
			printf("factor\n");
		else
			printf("neither\n");
	}
}