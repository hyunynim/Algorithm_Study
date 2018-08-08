#include<cstdio>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<utility>
#include<functional>
#include<cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	char msg[1234];
	bool chk[4] = { 1, 1, 1, 1 };
	while (~scanf("%s", msg)) {
		for (int i = 0; msg[i] != '\0'; ++i) {
			if (chk[0] == 1 && chk[1] == 1 && chk[2] == 1 && chk[3] == 1) {
				if (msg[i] == 'U') {
					chk[0] = 0;
				}
			}
			if (chk[0] == 0 && chk[1] == 1 && chk[2] == 1 && chk[3] == 1) {
				if (msg[i] == 'C') {
					chk[1] = 0;
				}
			}
			if (chk[0] == 0 && chk[1] == 0 && chk[2] == 1 && chk[3] == 1) {
				if (msg[i] == 'P') {
					chk[2] = 0;
				}
			}
			if (chk[0] == 0 && chk[1] == 0 && chk[2] == 0 && chk[3] == 1) {
				if (msg[i] == 'C') {
					chk[3] = 0;
					break;
				}
			}
		}
	}
	if (chk[0] == 0 && chk[1] == 0 && chk[2] == 0 && chk[3] == 0)
		printf("I love UCPC");
	else
		printf("I hate UCPC");
}