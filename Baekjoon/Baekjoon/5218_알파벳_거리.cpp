#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		char msg[2][30];
		scanf("%s %s", msg[0], msg[1]);
		int ans;
		int j = 0;
		printf("Distances:");
		while (msg[0][j] != '\0')
		{
			ans = msg[1][j] - msg[0][j] < 0 ? msg[1][j] - msg[0][j] + 26 : msg[1][j] - msg[0][j];
			++j;
			printf(" %d", ans);
		}
		printf("\n");
	}
}