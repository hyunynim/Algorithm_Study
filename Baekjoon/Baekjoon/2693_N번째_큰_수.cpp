#include <iostream>
#include <algorithm>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a[10];
		for (int j = 0; j < 10; j++)
			scanf("%d", &a[j]);
		std::sort(a, a + 10);
		printf("%d\n", a[7]);
	}
}