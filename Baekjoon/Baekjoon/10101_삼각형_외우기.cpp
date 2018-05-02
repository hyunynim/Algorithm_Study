#include<cstdio>

int main() {
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	if (a[0] + a[1] + a[2] != 180) {
		printf("Error");
		return 0;
	}
	else {
		if (a[0] == a[1] && a[1] == a[2])
			printf("Equilateral");
		else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2])
			printf("Isosceles");
		else
			printf("Scalene");
	}
}