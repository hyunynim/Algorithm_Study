#include <cstdio>
char s[52];
int c[27];
int center = -1;
int main() {
	fgets(s, 52, stdin);
	for (int i = 0; s[i]; ++i) {
		c[s[i] - 'A']++;
	}
	for (int i = 0; i <= 'Z' - 'A'; ++i) {
		if (c[i] % 2) {
			if (center == -1)
				center = i;
			else {
				puts("I'm Sorry Hansoo");
				return 0;
			}
		}
	}
	for (int i = 0; i <= 'Z' - 'A'; ++i) {
		if (c[i]) {
			for (int j = 0; j<c[i] / 2; ++j)
				putchar(i + 'A');
		}
	}
	if (center != -1)
		putchar(center + 'A');
	for (int i = 'Z' - 'A'; i >= 0; --i) {
		if (c[i]) {
			for (int j = 0; j<c[i] / 2; ++j)
				putchar(i + 'A');
		}
	}
}