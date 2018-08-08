#include<cstdio>
int ABS(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[123];
		scanf("%s", msg);
		int num1 = (msg[0] - 'A') * 26 * 26 + (msg[1] - 'A') * 26 + (msg[2] - 'A');
		int num2 = (msg[4] - '0') * 10 * 10 * 10 + (msg[5] - '0') * 10 * 10 + (msg[6] - '0') * 10 + (msg[7] - '0');
		if (ABS(num1 - num2) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
}