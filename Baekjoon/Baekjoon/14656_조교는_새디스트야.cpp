#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int a;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		if (a != i)
			res++;
	}
	printf("%d", res);
}