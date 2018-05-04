#include<cstdio>

int main() {
	int a, b = -1;
	int n;
	scanf("%d", &n);
	a = n / 5;
	for (int i = a; i >= 0; --i) {
		int tmp = n;
		tmp -= 5 * i;
		if (tmp % 2 == 0) {
			b = tmp/2;
			a = i;
			break;
		}
	}
	if (b == -1) {
		printf("-1");
		return 0;
	}
		printf("%d", a + b);
}