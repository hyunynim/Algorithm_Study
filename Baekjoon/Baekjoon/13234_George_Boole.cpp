#include<cstdio>
#include<string.h>

int main() {
	char msg[3][10];
	bool a, b;
	scanf("%s %s %s", msg[0], msg[1], msg[2]);
	if (strcmp(msg[0], "true") == 0)
		a = 1;
	else
		a = 0;

	if (strcmp(msg[2], "true") == 0)
		b = 1;
	else
		b = 0;

	if (strcmp(msg[1], "AND") == 0)
		a = a&b;
	else
		a = a | b;
	if (a)
		printf("true");
	else
		printf("false");

}