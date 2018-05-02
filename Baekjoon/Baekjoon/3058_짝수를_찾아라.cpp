#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int tmp, min = 2100000000;
		int res = 0;
		for (int j = 0; j < 7; ++j) {
			scanf("%d", &tmp);
			if (tmp % 2 == 0) {
				if (tmp < min)
					min = tmp;
				res += tmp;
			}
		}
		printf("%d %d\n", res, min);
	}
}