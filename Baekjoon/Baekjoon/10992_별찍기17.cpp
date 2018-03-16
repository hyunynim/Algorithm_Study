#include <stdio.h>

void print_star2(int space, int star, int no);
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		print_star2(n - i, i * 2 - 1, i);
	return 0;
}

void print_star2(int space, int star, int no)
{
	for (int i = 0; i < space; i++)
		printf(" ");
	if (no == 1 || no == n) {
		for (int i = 0; i < star; i++)
			printf("*");
	}
	else {
		printf("*");
		for (int i = 0; i < 2 * (no - 1) - 1; i++)
			printf(" ");
		printf("*");
	}
	printf("\n");
}