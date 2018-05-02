#include <cstdio>
#include <string.h>

int main() {
	char msg[1100], msg2[1100];
	scanf("%s %s", msg, msg2);
	if (strlen(msg) >= strlen(msg2))
		printf("go");
	else
		printf("no");
}