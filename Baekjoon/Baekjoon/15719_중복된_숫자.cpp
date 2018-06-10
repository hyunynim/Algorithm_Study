#include<cstdio>
int check[500001] = { 0 };

int main() {
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		check[tmp / 20] ^= (1 << (tmp % 20));
		if (check[tmp / 20] & (1 << (tmp % 20)));
		else {
			printf("%d", tmp);
			return 0;
		}
	}
}