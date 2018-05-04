#include<cstdio>

int snail[1000][1000] = { 0 };


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	enum {U, D, L, R};
	int input = n*n;
	for (int i = 0; i < n; ++i) {
		snail[i][0] = input;
		input--;
	}
	int tmp = n;
	int cur[2];
	cur[0] = n - 1;
	cur[1] = 0;
	int next = R;
	n--;
	while (n) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				switch (next) {
				case U:
					cur[0]--;
					break;
				case D:
					cur[0]++;
					break;
				case R:
					cur[1]++;
					break;
				case L:
					cur[1]--;
					break;
				}
				snail[cur[0]][cur[1]] = input;
				--input;
			}
			switch (next) {
			case U:
				next = L;
				break;
			case D:
				next = R;
				break;
			case R:
				next = U;
				break;
			case L:
				next = D;
				break;
			}
		}
		--n;
	}
	int resy, resx;
	for (int i = 0; i < tmp; ++i) {
		for (int j = 0; j < tmp; ++j) {
			if (snail[i][j] == k) {
				resy = i;
				resx = j;
			}
			printf("%d ", snail[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", resy + 1, resx + 1);

}