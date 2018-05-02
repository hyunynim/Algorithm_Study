#include <stdio.h>

int main() {
	int n;
	int max = -1;
	int maxIndex = 0;
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &n);
		if (max < n) {
			max = n;
			maxIndex = i + 1;
		}
	}
		printf("%d\n%d", max, maxIndex);
}