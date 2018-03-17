#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
	char msg[201];
	int range;
	do {
		scanf("%d", &range);
		if (range == 0)
			return 0;
		scanf("%s", msg);
		int len = strlen(msg);
		len /= range;
		int k = 0;
		char **ans = new char*[len];

		for (int i = 0; i < len; i++)
			ans[i] = new char[range];
		for (int i = 0; i < len; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < range; j++) {
					ans[i][j] = msg[k];
					k++;
				}
			}
			else {
				for (int j = range-1; j >=0; j--) {
					ans[i][j] = msg[k];
					k++;
				}
			}
		}
		for (int i = 0; i < range; i++) {
			for (int j = 0; j < len; j++) {
				printf("%c", ans[j][i]);
			}
		}
		printf("\n");
	} while (range != 0);
}