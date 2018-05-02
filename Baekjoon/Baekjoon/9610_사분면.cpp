#include <cstdio>

int main() {
	int n;
	int res[5] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (x > 0 && y > 0)
			res[0]++;
		else if (x < 0 && y > 0)
			res[1]++;
		else if (x < 0 && y < 0)
			res[2]++;
		else if (x > 0 && y < 0)
			res[3]++;
		else
			res[4]++;
	}
	for (int i = 0; i < 4; ++i)
		printf("Q%d: %d\n", i + 1, res[i]);
	printf("AXIS: %d", res[4]);
}