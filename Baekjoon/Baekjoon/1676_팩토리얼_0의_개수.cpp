#include <stdio.h>

int main() {
	int n, cnt5 = 0, tmp;
	scanf("%d", &n);
	for (int i = 5; i <= n; i++) {
		if (i % 5 == 0) {
			tmp = i;
			while (tmp % 5 == 0) {
				tmp /= 5;
				cnt5++;
			}
		}
	}
	printf("%d", cnt5);
}