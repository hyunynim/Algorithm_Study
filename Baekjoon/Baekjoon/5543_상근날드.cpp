#include <stdio.h>

int main() {
	int min1 = 2000, min2 = 2000;
	int tmp;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &tmp);
		if (tmp < min1)
			min1 = tmp;
	}
	for (int i = 0; i < 2; i++) {
		scanf("%d", &tmp);
		if (tmp < min2)
			min2 = tmp;
	}
	printf("%d", min1 + min2 - 50);
}