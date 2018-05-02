#include<cstdio>

int main() {
	int n;
	printf("%d", 5 ^ 2);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		printf("1");
	for (int i = 0; i < n - 1; ++i)
		printf("0");
}