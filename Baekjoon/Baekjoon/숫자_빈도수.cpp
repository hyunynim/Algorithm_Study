#include<cstdio>
int n, d;

int main() {
	scanf("%d %d", &n, &d);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int tmp = i;
		while (tmp > 0) {
			if (tmp % 10 == d)
				res++;
			tmp /= 10;
		}
	}
	printf("%d", res);
}