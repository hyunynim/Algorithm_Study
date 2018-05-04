#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		res += a*b;

	}
	printf("%d", res);
}