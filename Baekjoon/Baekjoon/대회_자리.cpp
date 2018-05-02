#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int p, m;
		scanf("%d %d", &p, &m);
		bool isChk[501] = { 0 };
		int tmp;
		int res = 0;
		for (int j = 0; j < p; ++j) {
			scanf("%d", &tmp);
			if (isChk[tmp])
				res++;
			else
				isChk[tmp] = 1;
		}
		printf("%d\n", res);
	}
}