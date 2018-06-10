#include<cstdio>

int main() {
	char msg[100];
	int dig = 0;
	scanf("%s", msg);
	if (msg[0] == '0') {
		if (msg[1] == 'x')
			dig = 16;
		else
			dig = 8;
	}
	else
		dig = 10;
	
	int i = dig == 10 ? 0 : (dig == 8 ? 1 : 2);
	int res = 0;
	while (msg[i] != '\0') {
		if ('a' <= msg[i] && msg[i] <= 'f')
			res = res*dig + msg[i] - 'a' + 10;
		else
			res = res*dig + msg[i] - '0';
		++i;
	}
	printf("%d", res);
}