#include <cstdio>

int main() {
	int a[2][5] = { 0 };
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &a[i][j]);
			a[i][4] += a[i][j];
		}
	}
	printf("%d", a[0][4] >= a[1][4] ? a[0][4] : a[1][4]);
}