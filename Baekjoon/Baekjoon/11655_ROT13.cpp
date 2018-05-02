#include <iostream>
#include <string.h>

int main() {
	char msg[150];
	fgets(msg, 150, stdin);
	int i = 0;
	while (msg[i] != '\0') {
		if ('a' <= msg[i] && msg[i] <= 'm')
			msg[i] += 13;
		else if ('n' <= msg[i] && msg[i] <= 'z')
			msg[i] -= 13;
		else if ('A' <= msg[i] && msg[i] <= 'M')
			msg[i] += 13;
		else if ('N' <= msg[i] && msg[i] <= 'Z')
			msg[i] -= 13;
		++i;
	}
	printf("%s", msg);
}