#include <stdio.h>

int main() {
	int n = 0, tmp;
	for (int j = 0; j < 3; j++) {
		n = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &tmp);
			n += tmp;
		}
		switch (n) {
		case 0:
			printf("D");
			break;
		case 3:
			printf("A");
			break;
		case 2:
			printf("B");
			break;
		case 1:
			printf("C");
			break;
		case 4:
			printf("E");
			break;
		}
		printf("\n");

	}
}