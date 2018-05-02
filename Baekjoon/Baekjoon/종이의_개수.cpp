#include<cstdio>

int paper[2187][2187];
int n;
int res[3] = { 0 };

bool ChkPaper(int sx, int sy, int ex, int ey) {
	int tmp = paper[sy][sx];
	bool isStop = 0;
	for (int i = sy; i < ey; ++i) {
		for (int j = sx; j < ex; ++j)
		{
			if (tmp != paper[i][j]) {
				return 0;
			}
		}
	}
	res[tmp + 1]++;
	return 1;
}

void Find(int sx, int sy, int ex, int ey) {
	if (!ChkPaper(sx, sy, ex, ey)) {
		int dist = (ex - sx) / 3;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				Find(sx + dist*i, sy + dist*j, sx + dist*(i + 1), sy + dist*(j + 1));
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &paper[i][j]);
	}
	Find(0, 0, n, n);
	printf("%d\n%d\n%d", res[0], res[1], res[2]);
}