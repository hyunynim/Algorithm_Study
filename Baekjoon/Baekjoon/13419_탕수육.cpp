#include<cstdio>
#include<string.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[255];
		scanf("%s", msg);
		if (strlen(msg) % 2) {
			for (int j = 0; j < strlen(msg); j += 2)
				printf("%c", msg[j]);
			for (int j = 1; j < strlen(msg); j += 2)
				printf("%c", msg[j]);
			printf("\n");
			for (int j = 1; j < strlen(msg); j += 2)
				printf("%c", msg[j]);
			for (int j = 0; j < strlen(msg); j += 2)
				printf("%c", msg[j]);
			printf("\n");
		}
		else {

			for (int j = 0; j < strlen(msg); j += 2)
				printf("%c", msg[j]);
			printf("\n");
			for (int j = 1; j < strlen(msg); j += 2)
				printf("%c", msg[j]);
			printf("\n");
		}
	}
}