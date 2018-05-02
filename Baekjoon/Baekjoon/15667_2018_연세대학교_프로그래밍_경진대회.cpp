#include<cstdio>
#include<math.h>

int main() {
	int n;
	scanf("%d", &n);
	int a;
	a = (-1 + sqrt(1 * 1 - 4 * 1 * (1 - n))) / 2;
	printf("%d", a);
}