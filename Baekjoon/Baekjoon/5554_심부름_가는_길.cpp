#include <iostream>

int main() {
	int m = 0, s = 0;
	int tmp, res = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &tmp);
		res += tmp;
	}
	printf("%d\n%d", res / 60, res % 60);
}