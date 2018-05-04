#include<cstdio>

int main() {
	int n;
	char a = 'F';
	char b = '9';

	scanf("%d", &n);
	n -= 2013;
	if (n == 0) {
		printf("F9");
		return 0;
	}
	if (n > 0) {
		n %= 60;
		for (int i = 0; i < n; ++i) {
			++a;
			++b;
			if (a > 'L')
				a = 'A';
			if (b > '9')
				b = '0';
		}
	}
	else {
		n = (-n) % 60;
		for (int i = 0; i < n; ++i) {
			--a;
			--b;
			if (a < 'A')
				a = 'L';
			if (b < '0')
				b = '9';
		}
	}
	printf("%c%c", a, b);
}