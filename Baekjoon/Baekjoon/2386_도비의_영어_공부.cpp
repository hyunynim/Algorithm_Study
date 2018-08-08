#include<cstdio>

int main() {
	char al, msg[1234];
	while (1) {
		int res = 0;
		al = getchar();
		if (al == '#')
			return 0;
		getchar();
		fgets(msg, 1230, stdin);
		for (int i = 0; msg[i] != '\0'; ++i) {
			if (msg[i] == al || msg[i] == al - 'a' + 'A')
				res++;
		}
		printf("%c %d\n", al, res);
	}
}