#include<cstdio>
#include<string.h>

int main() {
	char msg[2][200];
	char oper;
	scanf("%s", msg[0]);
	int len1 = strlen(msg[0]);
	getchar();
	scanf("%c", &oper);
	scanf("%s", msg[1]);
	int len2 = strlen(msg[1]);
	if (oper == '*') {
		printf("1");
		for (int i = 0; i < len1 + len2 - 2; ++i)
			printf("0");
		return 0;
	}
	else {
		if (len1 > len2) {
			msg[0][len1 - len2] = '1';
			for (int i = 0; i < len1; ++i)
				printf("%c", msg[0][i]);
		}
		else if (len1 < len2) {
			msg[1][len2 - len1] = '1';
			for (int i = 0; i < len2; ++i)
				printf("%c", msg[1][i]);
		}
		else {
			printf("2");
			for (int i = 0; i < len1 - 1; ++i)
				printf("0");
		}
	}
}