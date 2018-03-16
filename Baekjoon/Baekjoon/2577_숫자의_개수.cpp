#include <stdio.h>

int main()
{
	int a, b, c, mul, res[10] = { 0 };
	scanf("%d %d %d", &a, &b, &c);
	mul = a*b*c;
	while (mul / 10 != 0) {
		res[mul % 10]++;
		mul /= 10;
	}
	res[mul]++;
	for (int i = 0; i < 10; i++)
		printf("%d\n", res[i]);
}