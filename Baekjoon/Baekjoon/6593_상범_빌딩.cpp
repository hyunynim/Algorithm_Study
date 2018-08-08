#include<cstdio>
#include<string.h>
#include<tuple>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
int build[33][33][33];
bool chk[33][33][33];
int nx[] = { 0, 0, 0, 0, 1, -1 };
int ny[] = { 0, 0, 1, -1, 0, 0 };
int nz[] = { 1, -1, 0, 0, 0, 0 };
tuple<int, int, int> endPos;
int l, r, c;
int BFS(tuple<int, int, int> & s) {
	int L, R, C;
	tie(L, R, C) = s;

	queue<tuple<int, int, int>> q;
	q.push(s);
	chk[L][R][C] = 1;
	int curCnt = 1;
	int tmp;
	int ans = 0;
	while (q.size()) {
		tmp = 0;
		for (int i = 0; i < curCnt; ++i) {
			tuple<int, int, int> cur = q.front(); q.pop();
			tie(L, R, C) = cur;
			if (endPos == cur)
				return ans;
			for (int j = 0; j < 6; ++j) {
				int curL = L + nz[j];
				int curR = R + ny[j];
				int curC = C + nx[j];
				if (0 <= curL && curL < l
					&& 0 <= curR && curR < r
					&& 0 <= curC && curC < c
					&& !chk[curL][curR][curC]
					&& build[curL][curR][curC] != 1) {
					q.push({ curL, curR, curC });
					chk[curL][curR][curC] = 1;
					++tmp;
				}
			}
		}
		curCnt = tmp;
		++ans;
	}
	return 0;
}

int main() {
	while (1) {
		memset(build, 0, sizeof(build));
		memset(chk, 0, sizeof(chk));
		char msg[123];
		scanf("%d %d %d", &l, &r, &c);
		if (l == 0 && r == 0 && c == 0)
			return 0;
		tuple<int, int, int> start;
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < r; ++j) {
				scanf("%s", msg);
				for (int k = 0; k < c; ++k) {
					if (msg[k] == 'S') {
						build[i][j][k] = -1;
						start = { i, j, k };
					}
					else if (msg[k] == '.')
						build[i][j][k] = 0;
					else if (msg[k] == '#')
						build[i][j][k] = 1;
					else if (msg[k] == 'E'){
						build[i][j][k] = 2;
						endPos = { i,j,k };
					}
				}
			}
		}
		int ans = BFS(start);
		if (ans)
			printf("Escaped in %d minute(s).\n", ans);
		else
			printf("Trapped!\n");
	}
}