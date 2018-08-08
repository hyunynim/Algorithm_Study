#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

// O(n^2)

int dp[123][123][123];
int len1, len2, len3;
char msg[3][123];

int main() {
	scanf("%s %s %s", msg[0], msg[1], msg[2]);
	for (int k = 0; msg[2][k] != '\0'; ++k) {
		for (int i = 0; msg[1][i] != '\0'; ++i) {
			for (int j = 0; msg[0][j] != '\0'; ++j) {
				if (msg[1][i] == msg[0][j] && msg[2][k] == msg[1][i])
					dp[k + 1][i + 1][j + 1] = dp[k][i][j] + 1;

				else
					dp[k + 1][i + 1][j + 1] = max({ dp[k][i + 1][j + 1], dp[k + 1][i + 1][j], dp[k + 1][i][j + 1] });
			}
		}
	}
	len1 = strlen(msg[0]); len2 = strlen(msg[1]); len3 = strlen(msg[2]);

	printf("%d\n", dp[len3][len2][len1]);
}

/*comment*/
//3차원 dp를 하는 것과 2차원 dp의 결과로 한번더 2차원 dp를 한 것은 다름
//dababcf
//ababdef
//df		답:2	2차원: 1