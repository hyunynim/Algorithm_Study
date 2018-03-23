#include <stdio.h>

void print_star(int space, int star) {
	for (int i = 0; i < space; ++i)
		printf(" ");
	for (int i = 0; i < star; ++i)
		printf("*");
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		print_star(0, i + 1);
		print_star((n - i - 1) * 2, i + 1);
		printf("\n");
	}

		for (int i = 1; i < n; i++) {
			print_star(0, n - i);
			print_star(2 * i, n-i);
			printf("\n");
		}
}