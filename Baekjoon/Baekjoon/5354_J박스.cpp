#include <iostream>

int main() {
	int n, box;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &box);
		for (int j = 0; j < box; j++) {
			for (int k = 0; k < box; k++) {
				if ((k == 0 || k == box - 1) || (j == 0 || j == box - 1))
					printf("#");
				else
					printf("J");
			}
			printf("\n");
		}
		printf("\n");
	}
}