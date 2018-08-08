#include<cstdio>

int main() {
	int n;
	char msg[1234];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		int cnt = 0;
		bool isCon = 0;
		for (int j = 0; msg[j] != '\0'; ++j) {
			if (msg[j] == '(')
				++cnt;
			else {
				if (cnt)
					--cnt;
				else {
					printf("NO\n");
					isCon = 1;
					break;
				}
			}
		}
		if (isCon)
			continue;
		if (cnt)
			printf("NO\n");
		else
			printf("YES\n");
	}
}