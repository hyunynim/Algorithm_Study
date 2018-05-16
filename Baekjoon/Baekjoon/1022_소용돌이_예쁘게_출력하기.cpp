#include<cstdio>
#include<algorithm>

using namespace std;

int calc(int x, int y)
{
	if (x == 0 && y == 0) return 1;
	if (x <= 0 && y <= 0 && x >= y || x >= y && y <= 0 && x + y <= 0) {
		int upperLeft = (-2 * (y)+1)*(-2 * (y)+1) - (-y * 4);
		return upperLeft + (x - y);
	}
	if (x <= 0 && y <= 0 && x <= y || x <= 0 && y >= 0 && x + y <= 0) {
		int upperLeft = (-2 * (x)+1)*(-2 * (x)+1) - (-x * 4);
		return upperLeft + (x - y);
	}

	if (x == y)return (2 * x + 1)*(2 * x + 1);
	if (x <= y) {
		int lowerRight = (2 * y - 1)*(2 * y - 1);

		return lowerRight - (x - y);
	}
	int lowerRight = (2 * x + 1)*(2 * x + 1);
	return lowerRight + (y - x);
}
int digitCount(int n)
{
	int ret = 0;
	while (n) {
		n /= 10;
		++ret;
	}
	return ret;
}
int main()
{

	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	int maxDigit = max(digitCount(calc(r1, c1)), max(digitCount(calc(r1, c2)), max(digitCount(calc(r2, c2)), digitCount(calc(r2, c1)))));

	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			printf("%*d ", maxDigit, calc(i, j));
		}
		printf("\n");
	}
}