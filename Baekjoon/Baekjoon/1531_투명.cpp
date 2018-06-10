#include<cstdio>

int img[100][100] = { 0 };

void subPaper(int sx, int sy, int ex, int ey) {
	for (int i = sy; i <= ey; ++i) {
		for (int j = sx; j <= ex; ++j) {
			img[i][j]--;
		}
	}
}

int cntPaper() {
	int res = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (img[i][j] < 0)
				res++;
		}
	}
	return res;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			img[i][j] = m;
	}
	int sx, sy, ex, ey;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		subPaper(sx-1, sy-1, ex-1, ey-1);
	}
	printf("%d", cntPaper());
}

/*comment*/
//좌표의 범위가 1~100이었음