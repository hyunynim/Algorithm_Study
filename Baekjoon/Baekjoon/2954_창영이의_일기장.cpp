#include<cstdio>

int main() {
	char msg[1234];
	fgets(msg, 123, stdin);
	for (int i = 0; msg[i] != '\0'; ++i) {
		printf("%c", msg[i]);
		if (msg[i] == 'a'
			|| msg[i] == 'e'
			|| msg[i] == 'i'
			|| msg[i] == 'o'
			|| msg[i] == 'u')
			i += 2;
	}
}