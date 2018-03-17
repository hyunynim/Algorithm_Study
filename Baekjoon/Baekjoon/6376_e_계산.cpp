#include <stdio.h>

int main() {
	double e[10] = { 1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0 };
	for (int i = 7; i < 10; i++)
		e[i] = e[i - 1] * i;
	printf("n e\n");
	printf("- -----------\n");
	for (int i = 1; i < 10; i++) 
		e[i] = e[i - 1] + 1.0 / e[i];
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for (int i = 3; i < 10; i++) {
		printf("%d %-11.9lf\n", i, e[i]);
	}
}

/*comment*/
//자리수 잘못 체크함