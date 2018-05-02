#include <iostream>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int v, e, res;
		scanf("%d %d", &v, &e);
		res = 2 - v + e;
		printf("%d\n", res);
	}
}