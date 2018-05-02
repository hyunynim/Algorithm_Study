#include <iostream>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		int * num = new int[n];
		long long res = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &num[j]);
 		}
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; ++k) {
				if (num[j] * num[k] != 0)
					res += gcd(num[j], num[k]);
			}
		}
		printf("%lld\n", res);
	}
}