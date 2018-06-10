#include<cstdio>
#include<string.h>

int main() {
	while (1) {
		char msg[12345];
		fgets(msg, 12344, stdin);
		int res = 0;
		if (msg[0] == '#')
			return 0;
		else {
			int i = 0;
			while (msg[i] != '\0') {
				if (msg[i] == 'a'
					|| msg[i] == 'e'
					|| msg[i] == 'i'
					|| msg[i] == 'o'
					|| msg[i] == 'u'
					|| msg[i] == 'A'
					|| msg[i] == 'E'
					|| msg[i] == 'I'
					|| msg[i] == 'O'
					|| msg[i] == 'U')
					++res;
				++i;
			}
		}
		printf("%d\n", res);
	}
}