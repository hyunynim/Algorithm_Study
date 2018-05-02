#include <cstdio>

int main() {
	char msg[200];
	scanf("%s", msg);
	int i = 0;
	while (msg[i] != '\0') {
		switch (msg[i]) {
		case 'C':
		case 'A':
		case 'M':
		case 'B':
		case 'R':
		case 'I':
		case 'D':
		case 'G':
		case 'E':
			break;
		default:
			printf("%c", msg[i]);
			break;
		}
		++i;
	}
}