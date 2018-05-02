#include <cstdio>

int main() {
	char msg[200];
	scanf("%s", msg);
	int i = 0;
	while (msg[i] != '\0') {
		if ('a' <= msg[i] && msg[i] <= 'z')
			msg[i] = msg[i] - 'a' + 'A';
		else
			msg[i] = msg[i] - 'A' + 'a';
		++i;
	}
	printf("%s", msg);
}