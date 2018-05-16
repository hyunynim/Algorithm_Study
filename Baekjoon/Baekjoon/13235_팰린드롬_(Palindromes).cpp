#include<cstdio>
#include<string.h>
int main() {
	char msg[30];
	scanf("%s", msg);
	int len = strlen(msg);
	for (int i = 0; i < len / 2; ++i) {
		if (msg[i] != msg[len - i - 1]) {
			printf("false");
			return 0;
		}
	}
	printf("true");
}