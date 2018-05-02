#include <cstdio>

int main() {
	int l, a, b, c, d;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	int resa, resb;
	if (a%c == 0)
		resa = a / c;
	else
		resa = a / c + 1;
	if (b%d == 0)
		resb = b / d;
	else
		resb = b / d + 1;

	int max = resa > resb ? resa : resb;
	printf("%d", l - max);
}
