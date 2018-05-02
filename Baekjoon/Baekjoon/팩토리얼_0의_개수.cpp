#include <stdio.h>
#define MIN(x, y) x > y ? y : x

int pow(int n, int p) {
	int res = 1;
	while (p > 0) {
		if (p % 2 != 0) {
			res *= n;
		}
		n *= n;
		p /= 2;
	}
	return res;
}

int main() {
	int t, ans, calc, n, k, mul[13] = { 0, 1, 6, 31, 156, 781,3906,19531,97656,488281,2441406,12207031,61035156 };
		ans = 0;
		scanf("%d", &n);
		while (n > 1) {
			k = 1;
			while ((n / pow(5, k)) != 0 && k<13)
				k++;
			k--;
			if (k == 0) break;
			ans += (n / pow(5, k)) * mul[k];
			n %= pow(5, k);
		}
		printf("%d\n", ans);
}