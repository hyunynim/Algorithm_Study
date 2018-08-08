#include<cstdio>

int main() {
	while (1) {
		char msg[1234];
		bool chk[26] = { 0 };
		fgets(msg, 231, stdin);
		if (msg[0] == '*')
			return 0;
		for (int i = 0; msg[i] != '\0'; ++i) {
			if ('a' <= msg[i] && msg[i] <= 'z')
				chk[msg[i] - 'a'] = 1;
		}
		bool ans = 0;
		for (int i = 0; i < 26; ++i) {
			if (!chk[i])
				ans = 1;
		}
		if (ans)
			puts("N");
		else
			puts("Y");
	}
}