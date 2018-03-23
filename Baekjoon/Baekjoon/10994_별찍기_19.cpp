#include <stdio.h>

bool star[400][400] = { 0 };

void print_star(int xi, int yi, int size) {
	if (size == 1)
		star[xi][yi] = 1;
	else {
		for (int i = 0; i <= 2 * (size - 1); i++) {
			star[xi - (2 * (size - 1))][yi + i] = 1;
			star[xi + (2 * (size - 1))][yi + i] = 1;
			star[xi - (2 * (size - 1))][yi - i] = 1;
			star[xi + (2 * (size - 1))][yi - i] = 1;
			star[xi + i][yi - (2 * (size - 1))] = 1;
			star[xi + i][yi + (2 * (size - 1))] = 1;
			star[xi - i][yi - (2 * (size - 1))] = 1;
			star[xi - i][yi + (2 * (size - 1))] = 1;
		}
		print_star(xi, yi, size - 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	print_star(2 * (n - 1), 2 * (n - 1), n);
	for (int i = 0; i < 1 + 4 * (n - 1); i++) {
		for (int j = 0; j < 4 * (n - 1)+1; j++) {
			if (star[j][i])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}