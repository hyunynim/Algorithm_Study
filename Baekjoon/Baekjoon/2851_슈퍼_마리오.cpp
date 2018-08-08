#include<cstdio>

int ABS(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n, sum = 0;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &n);
		if (ABS(100 - (sum + n)) <= ABS(100 - sum))
			sum += n;
		else
			break;
	}
	printf("%d", sum);
}