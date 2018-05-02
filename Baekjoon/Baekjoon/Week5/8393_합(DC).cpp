#include <stdio.h>

int sum(int n) {
	if (n == 1)
		return 1;
	else {
		if (n % 2 == 1)
			return sum(n - 1) + n;
		else
			return sum(n / 2)*2 + n*n / 4;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", sum(n));
}