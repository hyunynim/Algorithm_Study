#include<cstdio>

int stringSum(char * msg) {
	int sum = 0;
	int i = 0;
	while (msg[i] != '\0' && msg[i] != '\n') {
		int tmp = 0;
		while (msg[i] != ' ' && msg[i] != '\0' && msg[i] != '\n') {
			tmp = tmp * 10 + (msg[i] - '0');
			++i;
		}
		++i;
		sum += tmp;
	}
	return sum;
}

int main() {
	int t, n;
	char msg[123456];
	scanf("%d", &t);
	getchar();
	for (int i = 0; i < t; ++i) {
		fgets(msg, 123455, stdin);
		printf("%d\n", stringSum(msg));
	}
}