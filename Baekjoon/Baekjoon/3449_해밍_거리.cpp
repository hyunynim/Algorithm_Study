#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[2][1234];
		scanf("%s %s", msg[0], msg[1]);
		int res = 0;
		for (int j = 0; msg[0][j] != '\0'; ++j) {
			if (msg[0][j] == msg[1][j]);
			else
				++res;
		}
		printf("Hamming distance is %d.\n", res);
	}
}