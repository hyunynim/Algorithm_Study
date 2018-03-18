#include <stdio.h>

int main() {
	int n, line;
	scanf("%d", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	else {
		line = 0;
		while (1) {
			line++;
			if (6 * (line*(line - 1) / 2 + 1) - 4 <= n && n <= 6 * (line*(line - 1) / 2 + 1) - 5 + line * 6)
				break;
		}
		printf("%d", line+1);
	}
}