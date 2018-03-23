#include <stdio.h>
bool star[2200][2200];

int power(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2 != 0)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

void print_star(int xi, int yi, int size) {
	if (size == 1) {
		star[xi][yi] = 1;
		for (int i = 1; i < 3; i++) {
			star[xi + i][yi] = 1;
			star[xi][yi + i] = 1;
			star[xi + i][yi + 2] = 1;
			star[xi + 2][yi + i] = 1;
		}
	}
	else {
		print_star(xi, yi, size - 1);
		for (int i = 1; i < 3; i++) {
			print_star(xi + i * power(3, size - 1), yi, size - 1);
			print_star(xi, yi + i * power(3, size - 1), size - 1);
			print_star(xi + 2 * power(3, size - 1), yi + i * power(3, size - 1), size - 1);
			print_star(xi + i * power(3, size - 1), yi + 2 * power(3, size - 1), size - 1);

		}
	}
}

int main() {
	int n, dig = 0;
	scanf("%d", &n);
	int tmp = n;
	if (n == 1) {
		printf("*");
		return 0;
	}
	while (n > 0) {
		n /= 3;
		dig++;
	}
	print_star(0, 0, dig - 1);
	for (int i = 0; i < tmp; i++) {
		for (int j = 0; j < tmp; j++) {
			if (star[j][i])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}