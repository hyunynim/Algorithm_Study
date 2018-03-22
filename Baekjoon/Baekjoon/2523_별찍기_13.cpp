#include <stdio.h>

void print_star(int space, int star) {
	for (int i = 0; i < space; i++)
		printf(" ");
	for (int i = 0; i < star; i++)
		printf("*");
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		print_star(0, i + 1);
	for (int i = 0; i < n - 1; i++)
		print_star(0, n - i - 1);
}