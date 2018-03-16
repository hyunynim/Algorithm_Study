#include <stdio.h>

int main() {
	bool chk = 0;
	int a, b, c;
	char oper;
	scanf("%d %d %d", &a, &b, &c);
	if (a + b == c)
		oper = '+';
	else if (a - b == c)
		oper = '-';
	else if (a * b == c)
		oper = '*';
	else if (a / b == c)
		oper = '/';
	else {
		chk = 1;
		if (a == b + c)
			oper = '+';
		else if (a == b - c)
			oper = '-';
		else if (a == b*c)
			oper = '*';
		else if (a == b / c)
			oper = '/';
	}
	if (chk == 0)
		printf("%d%c%d=%d", a, oper, b, c);
	else
		printf("%d=%d%c%d", a, b, oper, c);
}