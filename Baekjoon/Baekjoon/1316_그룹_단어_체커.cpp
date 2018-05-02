#include <cstdio>

int main() {
	int n, res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[200];
		scanf("%s", msg);

		bool chk[26] = { 0 };
		bool isCnt = 1;
		int j = 0;
		char tmp;
		while (msg[j] != '\0') {
			if (chk[msg[j] - 'a'] == 0) {
				tmp = msg[j];
				chk[msg[j] - 'a'] = 1;
				while (msg[j] == tmp && msg[j] != '\0')
					++j;
			}
			else {
				isCnt = 0;
				break;
			}
		}
		res += isCnt;
	}
	printf("%d", res);
}