#include<cstdio>

double Min(double a, double b) {
	return a > b ? b : a;
}

int main() {
	double a, b, c, j, k, l;

	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &j, &k, &l);
	double cnt = Min(a / j, Min(b / k, c / l));
	printf("%.4lf %.4lf %.4lf", a - j * cnt, b - k * cnt, c - l * cnt);
}