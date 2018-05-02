#include <iostream>

int main() {
	int m = 1, f = 1;
	while (m != 0 && f != 0) {
		scanf("%d %d", &m, &f);
		if (m != 0 && f!=0)
		printf("%d\n", m + f);
	}
}