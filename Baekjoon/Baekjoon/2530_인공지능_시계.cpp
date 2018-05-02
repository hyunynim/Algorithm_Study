#include <iostream>

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	a += d / 3600;
	d %= 3600;
	b += d / 60;
	c += d % 60;
	b += c / 60;
	c %= 60;
	a += b / 60;
	b %= 60;
	a %= 24;
	printf("%d %d %d", a, b, c);
}