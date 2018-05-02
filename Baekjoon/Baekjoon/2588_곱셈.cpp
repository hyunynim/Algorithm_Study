#include <iostream>

int main() {
	int a, b, tmp;
	scanf("%d %d", &a, &b);
	tmp = b;
	while (b > 0) {
		printf("%d\n", a*(b % 10));
		b /= 10;
	}
	printf("%d", a*tmp);
}