#include<cstdio>

int main() {
	int n, m;
	char msg[2][1123];
	scanf("%d %d", &n, &m);
	scanf("%s", msg[0]);
	for (int i = 0; i < m; ++i) {
		scanf("%s", msg[1]);
		int j = 0, k = 0;
		while (msg[0][j] != '\0' && msg[1][k] != '\0') {
			if (msg[0][j] == msg[1][k])
				++j;
			++k;
		}
		if ((msg[0][j] == '\0' && msg[0][k] == '\0') || msg[0][j] == '\0')
			printf("true\n");
		else
			printf("false\n");
	}
}