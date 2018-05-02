#include <cstdio>

int main() {
	double a, b, c, d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

	double max = a / c + b / d;
	int maxIndex = 0;
	if (c / d + a / b > max) {
		max = c / d + a / b;
		maxIndex = 1;
	}
	if (d / b + c / a > max) {
		max = d / b + c / a;
		maxIndex = 2;
	}

	if (b / a + d / c > max) {
		max = b / a + d / c;
		maxIndex = 3;
	}
	printf("%d", maxIndex);
}