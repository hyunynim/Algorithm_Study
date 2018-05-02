#include <iostream>

int main() {
	int max = -10;
	int tmp = 0;
	int res = 0;

	for (int i = 0; i < 8; i++) {
		scanf("%d", &tmp);
		if (i % 2 == 0)
			res -= tmp;
		else
			res += tmp;

		if (max < res)
			max = res;
	}
	printf("%d", max);
}