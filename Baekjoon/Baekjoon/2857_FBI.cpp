#include <cstdio>

int main() {
	int res = 0;
	for (int i = 0; i < 5; ++i) {
		char msg[100];
		scanf("%s", msg);
		int j = 0;
		while (msg[j+2] != '\0') {
			if (msg[j] == 'F' && msg[j + 1] == 'B' && msg[j + 2] == 'I') {
				printf("%d ", i + 1);
				++res;
			}
			++j;
		}
	}
	if (res == 0)
		printf("HE GOT AWAY!");
}