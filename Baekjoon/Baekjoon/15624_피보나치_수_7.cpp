#include <iostream>

#define M 1000000007

void ChangeInt(int * a, int * b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int main() {
	int n;
	scanf("%d", &n);
	int a = 0, b = 1, c;
	if (n == 0)
		printf("0");
	else if (n == 1 || n == 2)
		printf("1");
	else {
		for (int i = 1; i<n; ++i) {
			c = (a + b) % M;
			ChangeInt(&a, &b);
			ChangeInt(&b, &c);
		}
		printf("%d", b);
	}
}