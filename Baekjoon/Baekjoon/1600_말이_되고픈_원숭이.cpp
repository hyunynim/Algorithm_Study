#include<cstdio>
#include<string.h>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;

bool map[234][234];
int chk[32][201][201];
int dx[] = { 0, 0, 1, -1, -2, -1, -2, -1, 2, 1, 2, 1 };
int dy[] = { 1, -1, 0, 0, -1, -2, 1, 2, -1, -2, 1, 2 };
int dt[] = { 0, 0, 0, 0,  -1, -1, -1, -1, -1, -1, -1, -1 };
int k, w, h;

int enc(int x, int y, int t) {
	return x * 100000 + y * 100 + t;
}
void dec(int num, int & x, int & y, int & t) {
	t = num % 100;
	num /= 100;
	y = num % 1000;
	num /= 1000;
	x = num;
}

int main() {
	scanf("%d %d %d", &k, &w, &h);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	queue<int> q;
	q.push(enc(0, 0, k));
	int curCnt = 1;
	int tmp = 0;
	int ans = 0;
	chk[k][0][0] = 1;
	while (q.size()) {
		for (int TC = 0; TC < curCnt; ++TC) {
			int x, y, toPick, cur = q.front(); q.pop();
			dec(cur, x, y, toPick);
			if (x == w - 1 && y == h - 1) {
				printf("%d", ans);
				return 0;
			}
			for (int i = 0; i < 12; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nt = toPick + dt[i];
				if (0 <= nx && nx < w
					&& 0 <= ny && ny < h
					&& nt >= 0
					&& !map[ny][nx]
					&& !chk[nt][ny][nx]) {
					q.push(enc( nx, ny, nt ));
					chk[nt][ny][nx] = 1;
					++tmp;
				}
			}
		}
		++ans;
		curCnt = tmp;
		tmp = 0;
	}
	printf("%d", -1);
}