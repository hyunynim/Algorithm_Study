#include <stdio.h>

int main() {
	char msg[101];
	scanf("%s", msg);
	int res = 0, i = 0;
	while (msg[i] != NULL) {
		if (i + 1 < 101) {
			if (msg[i] == 'c') {
				if (msg[i + 1] == '=' || msg[i + 1] == '-') {
					++res;
					i += 2;
					continue;
				}
			}
			else if (msg[i] == 'd') {
				if (i + 2 < 101 && msg[i + 1] == 'z' && msg[i + 2] == '=') {
					++res;
					i += 3;
					continue;
				}
				else if (msg[i + 1] == '-') {
					++res;
					i += 2;
					continue;
				}
			}
			else if (msg[i] == 'l' && msg[i + 1] == 'j') {
				++res;
				i += 2;
				continue;
			}
			else if (msg[i] == 'n' && msg[i + 1] == 'j') {
				++res;
				i += 2;
				continue;
			}
			else if (msg[i] == 's' && msg[i + 1] == '=') {
				++res;
				i += 2;
				continue;
			}
			else if (msg[i] == 'z' && msg[i + 1] == '=') {
				++res;
				i += 2;
				continue;
			}
		}
		++res;
		++i;
	}
	printf("%d", res);
}