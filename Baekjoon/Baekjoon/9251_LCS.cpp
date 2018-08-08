#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int dp[1004][1004];

int main() {
	char msg[2][1234];
	scanf("%s %s", msg[0], msg[1]);
	for (int i = 0; msg[1][i] != '\0'; ++i) {
		for (int j = 0; msg[0][j] != '\0'; ++j) {
			if (msg[1][i] == msg[0][j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	int len1 = strlen(msg[0]), len2 = strlen(msg[1]);
	printf("%d", dp[len2][len1]);
}