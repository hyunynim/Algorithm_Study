#include<cstdio>
#include<string.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[200];
		scanf("%s", msg);
		printf("%c%c\n", msg[0], msg[strlen(msg) - 1]);
	}
}