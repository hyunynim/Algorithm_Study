#include <stdio.h>

int main() {
	char msg[101];
	scanf("%s", msg);
	printf("%c", msg[0]);
	int i = 1;
	while (msg[i] != '\0') {
		if (msg[i] == '-')
			printf("%c", msg[i + 1]);
		i++;
	}
}