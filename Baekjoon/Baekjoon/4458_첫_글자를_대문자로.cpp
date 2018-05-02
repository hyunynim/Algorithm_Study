#include <iostream>

int main() {
	char msg[60];
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		fgets(msg, 60, stdin);
		int j = 0;
		while (msg[j] != '\0') {
			if (j == 0) {
				if ('a' <= msg[j] && msg[j] <= 'z')
					printf("%c", msg[j] - 'a' + 'A');
				else
					printf("%c", msg[j]);
			}
			else
				printf("%c", msg[j]);
			++j;
		}
	}
}