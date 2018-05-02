#include <iostream>

int main() {
	char msg[1000];
	int degree;
	scanf("%s %d", msg, &degree);

	int result = 0;
	int i = 0;
	while (msg[i] != '\0') {
		int tmp;
		if ('0' <= msg[i] && msg[i] <= '9')
			tmp = msg[i] - '0';
		else if ('A' <= msg[i] && msg[i] <= 'Z') {
			tmp = msg[i] - 'A' + 10;
		}
		result = result*degree + tmp;
		++i;
	}
	printf("%d", result);
}