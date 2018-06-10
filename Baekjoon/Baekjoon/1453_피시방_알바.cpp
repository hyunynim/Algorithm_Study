#include<cstdio>

int main() {
	int n;
	bool check[200] = { 0 };
	scanf("%d", &n);
	int tmp, res = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (check[tmp])
			res++;
		else
			check[tmp] = 1;
	}
	printf("%d", res);
}