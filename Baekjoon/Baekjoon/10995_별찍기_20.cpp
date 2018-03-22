#include <stdio.h>

void print_star(int i, int star) {
	if (i % 2 == 1)
		printf(" ");
	for (int i = 0; i < 2 * star - 1; i++) {
		if (i % 2 == 0)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		print_star(i, n);
}