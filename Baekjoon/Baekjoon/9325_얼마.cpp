#include <iostream>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		long long res;
		scanf("%lld", &res);
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			long long a, b;
			scanf("%lld %lld", &a, &b);
			res += a*b;
		}
		printf("%lld\n", res);
	}
}

/*comment*/
//overflow 고려 안함