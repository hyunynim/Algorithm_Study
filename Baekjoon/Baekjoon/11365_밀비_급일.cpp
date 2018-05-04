#include<cstdio>
#include<string.h>

int main() {
	char msg[600];
	fgets(msg, 600, stdin);
	while (strcmp(msg, "END\n") != 0) {
		for (int i = strlen(msg) - 2; i >= 0; --i)
			printf("%c", msg[i]);
		printf("\n");
		fgets(msg, 600, stdin);
	}
}