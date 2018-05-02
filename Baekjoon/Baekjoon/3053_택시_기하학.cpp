#define PI 3.14159265358979323846
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	printf("%.6lf\n", n*n*PI);
	printf("%.6lf", (double)n*(double)n*2.0);
}