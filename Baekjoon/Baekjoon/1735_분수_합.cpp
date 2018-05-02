#include <cstdio>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int resu, resd;
	resu = a*d + b*c;
	resd = b*d;
	int gcdn = gcd(resu, resd);
	resu /= gcdn;
	resd /= gcdn;
	printf("%d %d", resu, resd);
}