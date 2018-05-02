#include <stdio.h>
#include <string.h>

int main() {
	char msg[200];
	while (fgets(msg, 200, stdin) != NULL) {
		int i = 0;
		int res[4] = { 0 };
		while (msg[i] != '\0' && msg[i] != '\n') {
			if ('a' <= msg[i] && msg[i] <= 'z')
				res[0]++;
			else if ('A' <= msg[i] && msg[i] <= 'Z')
				res[1]++;
			else if ('0' <= msg[i] && msg[i] <= '9')
				res[2]++;
			else if (msg[i] == ' ')
				res[3]++;
			++i;
		}
		for (int j = 0; j < 4; ++j)
			printf("%d ", res[j]);
		printf("\n");
	}
}