#include<cstdio>

int main() {
	int testCase;
	scanf("%d", &testCase);
	for (int t = 0; t < testCase; ++t) {
		int a, b;
		char msg[1000010];
		scanf("%d %d %s", &a, &b, msg);
		int i = 0;
		for (; msg[i] != '\0'; ++i) {
			printf("%c", (a*(msg[i] - 'A') + b) % 26 + 'A');
		}
		printf("\n");
	}
}