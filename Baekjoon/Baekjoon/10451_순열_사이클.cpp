#include <cstdio>
#include <string.h>

int link[1001];
bool checked[1001];

bool CheckCycle(int start, int  next) {
	if (checked[start] == 1)
		return 0;
	if (next == start) {
		checked[start] = 1;
		return 1;
	}
	else {
		checked[next] = 1;
		CheckCycle(start, link[next]);
	}
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		memset(link, 0, sizeof(link));
		memset(checked, 0, sizeof(checked));
		int tmp;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			link[i + 1] = tmp;
		}

		int res = 0;
		for (int j = 1; j <= n; ++j) {
			if (CheckCycle(j, link[j])) {
				res++;
			}
		}
		printf("%d\n", res);

	}
}

/*comment*/
//result check하는 과정에서 < n까지 밖에 안해줌 -> <= n