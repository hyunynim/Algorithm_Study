#include <stdio.h>

int main() {
	int a, b, c, d, p;
	int sumX, sumY;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
	sumX = a*p;
	if (p > c) {
		sumY = b + (p - c)*d;
	}
	else
		sumY = b;
	if (sumX > sumY)
		printf("%d", sumY);
	else
		printf("%d", sumX);
}