#include <stdio.h>

int main() {
	int a, b, c, res;
	scanf("%d %d %d", &a, &b, &c);
	if (a == 1)
		res = (b - 2)*(c - 2);
	else if (b == 1)
		res = (a - 2)*(c - 2);
	else if (c == 1)
		res = (a - 2)*(b - 2);
	else
		res = ((a - 2) * 2 + (b - 2) * 2)*2 + 4*(c-2);
	printf("%d", res);
}