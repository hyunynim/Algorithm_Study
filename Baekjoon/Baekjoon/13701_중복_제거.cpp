#include<cstdio>

int main() {
	int num[1 << 20] = { 0 };
	int n;
	while (scanf("%d", &n) != EOF) {
		if (num[n / 32] & (1 << (n % 32)));
		else {
			printf("%d ", n);
			num[n / 32] |= (1 << (n % 32));
		}
	}
}