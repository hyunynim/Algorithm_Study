#include <stdio.h>

int gcd(int a, int b);
int cm(int a, int b, int gcd);

int main()
{
	int a, b, n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);

		printf("%d %d\n", cm(a, b, gcd(a, b)), gcd(a, b));
	}
	return 0;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int cm(int a, int b, int gcd) {
	return (a / gcd)*(b / gcd)*gcd;
}