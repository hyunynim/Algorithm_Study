#include <stdio.h>

int main() {
	char msg[200];
	scanf("%s", msg);
	int i = 0, cnt = 0;
	while (msg[i] != '\0') {
		if (msg[i] == 'a' || msg[i] == 'e' || msg[i] == 'i' || msg[i] == 'o' || msg[i] == 'u')
			cnt++;
		++i;
	}
	printf("%d", cnt);
}