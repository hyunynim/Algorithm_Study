#include <iostream>

int calc(int k, int n) {
	if (k == 0)
		return n;
	if (n == 1)
		return 1;
	else
		return calc(k - 1, n) + calc(k, n - 1);
}

int main() {
	int t, n, k;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", calc(k, n));
	}
}