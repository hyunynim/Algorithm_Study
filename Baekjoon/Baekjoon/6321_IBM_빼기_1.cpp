#include <stdio.h>

int main() {
	int t;
	char msg[51];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%s", msg);
		printf("String #%d\n", i + 1);
		for (int j = 0; msg[j] != '\0'; j++) {
			if (msg[j] == 'Z') {
				printf("A");
				continue;
			}
			printf("%c", msg[j] + 1);
		}
		printf("\n\n");
	}
}