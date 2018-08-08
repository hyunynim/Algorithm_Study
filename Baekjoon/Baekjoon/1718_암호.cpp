#include<cstdio>
#include<string.h>
int main() {
	char msg[34567];
	char crypt[34567];
	fgets(msg, 34566, stdin);
	scanf("%s", crypt);
	
	int len = strlen(msg);
	int len2 = strlen(crypt);
	for (int i = 0; i < len; ++i) {
		if (msg[i] == '\n')
			continue;
		if (msg[i] != ' ') {
			msg[i] -= (crypt[i % len2] - 'a' + 1);
			if (msg[i] < 'a')
				msg[i] += 26;
		}
		printf("%c", msg[i]);
	}
}