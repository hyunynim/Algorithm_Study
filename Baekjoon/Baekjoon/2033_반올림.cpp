#include<cstdio>

int pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

int main() {
	int n;
	int cnt = 1;
	scanf("%d", &n);
	while (1) {
		if (n > pow(10, cnt)) {
			n += 5 * pow(10, cnt - 1);
			n = n - (n % pow(10, cnt));
		}
		else {
			printf("%d", n);
			return 0;
		}
		++cnt;
	}
}