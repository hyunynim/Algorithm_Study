#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int pos;
		char msg[85];
		scanf("%d %s", &pos, msg);
		for (int j = pos - 1; j < strlen(msg) - 1; ++j)
			msg[j] = msg[j + 1];
		printf("%s");
	}
}