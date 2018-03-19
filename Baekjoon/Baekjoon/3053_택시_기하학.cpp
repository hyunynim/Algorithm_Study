#define PI 3.141592
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	printf("%.6lf\n", n*n*PI);
	printf("%.6lf", (double)n*n * 2.0);
}