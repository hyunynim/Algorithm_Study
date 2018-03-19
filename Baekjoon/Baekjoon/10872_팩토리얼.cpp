#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n == 0)
		printf("1");
	else {
		int res = 1;
		for (int i = 1; i <= n; i++)
			res *= i;
		printf("%d", res);
	}
}