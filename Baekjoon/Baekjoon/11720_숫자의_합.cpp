#include <stdio.h>

int main() {
	int n, num, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%1d", &num);
		sum += num;
	}

	printf("%d", sum);
}