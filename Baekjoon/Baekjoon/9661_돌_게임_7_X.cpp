#include <cstdio>

int main() {
	long long n;
	scanf("%lld", &n);
	n = (n - 1) % 5 + 1;
	puts(n == 2 || n == 5 ? "CY" : "SK");
}