#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", n / 5 + (n % 5 == 0 ? 0 : 1));
}