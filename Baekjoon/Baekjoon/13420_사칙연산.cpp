#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		long long a, b, c;
		char msg[123];
		char tmp[123];
		bool w = 1;
		scanf("%lld %s %lld %s %lld", &a, msg, &b, tmp, &c);
		switch (msg[0]) {
		case '+':
			if (a + b == c) {
				printf("correct\n");
				w = 0;
			}
			break;
		case '-':
			if (a - b == c) {
				printf("correct\n");
				w = 0;
			}
			break;
		case '*':
			if (a * b == c) {
				printf("correct\n");
				w = 0;
			}
			break;
		case '/':
			if (a / b == c) {
				printf("correct\n");
				w = 0;
			}
			break;
		}
		w && printf("wrong answer\n");
	}
}