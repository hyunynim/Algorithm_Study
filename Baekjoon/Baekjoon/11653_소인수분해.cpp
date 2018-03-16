#include <stdio.h>

int main() {
	long long n, i = 2;
	scanf("%lld", &n);
	while (n > 1) {
		if (n % i == 0) {
			printf("%lld\n", i);
			n /= i;
		}
		else
			i++;
	}
}