#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		char msg[50];
		fgets(msg, 49, stdin);
		int j = 0;
		int res = 0;
		while (msg[j] != '\0') {
			if ('A' <= msg[j] && msg[j] <= 'Z')
				res += msg[j] - 'A' + 1;
			++j;
		}
		if (res == 100)
			printf("PERFECT LIFE\n");
		else
			printf("%d\n", res);
	}
}