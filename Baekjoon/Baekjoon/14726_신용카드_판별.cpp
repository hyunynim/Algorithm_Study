#include<cstdio>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int k, res = 0, tmp;
		for (int j = 0; j < 16; ++j) {
			scanf("%1d", &k);
				if (j % 2 == 0) {
					k *= 2;
					tmp = k / 10 + k % 10;
					k = tmp;
				}
				res += k;
		}
		if ((res % 10) == 0)
			printf("T\n");
		else
			printf("F\n");
	}
}