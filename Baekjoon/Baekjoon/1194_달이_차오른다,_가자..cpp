#include<cstdio>
#include<queue>
#include<tuple>

using namespace std;

bool chk[60][60][1 << 6];
int graph[60][60];
int main() {
	int n, m;
	char msg[123];
	int curX, curY;
	int finX, finY;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		for (int j = 0; j < m; ++j) {
			int tmp = 0;
			switch (msg[j]) {
			case '.':
				tmp = 1;
				break;
			case '#':
				tmp = 0;
				break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				tmp = msg[j];
				break;
			case '0':
				tmp = 1;
				curX = j;
				curY = i;
				break;
			case '1':
				tmp = 999999;
				finX = j;
				finY = i;
				break;
			}
			graph[i][j] = tmp;
		}
	}
	int nx[4] = { 0, 0, 1, -1 };
	int ny[4] = { 1, -1, 0, 0 };
	queue<tuple<int, int, int>> q;
	q.push({ curX, curY, 0 });
	chk[curY][curX][0] = 1;
	int ans = 0;
	int curCnt = 1;
	int tmp;
	while (q.size()) {
		int x, y, key;
		tmp = 0;
		for (int TC = 0; TC < curCnt; ++TC) {
			tie(x, y, key) = q.front();
			if (graph[y][x] == 999999) {
				printf("%d", ans);
				return 0;
			}
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int cx = x + nx[i];
				int cy = y + ny[i];
				if (x + nx[i] < 0 || y + ny[i] < 0 || x + nx[i] >= m || y + ny[i] >= n)
					continue;
				else {
					if ('a' <= graph[cy][cx] && graph[cy][cx] <= 'f') {
						if (!chk[cy][cx][key]) {
							chk[cy][cx][key] = 1;
							q.push({ cx, cy, key | (1 << (graph[cy][cx] - 'a')) });
							++tmp;
						}
					}
					else if ('A' <= graph[cy][cx] && graph[cy][cx] <= 'F') {
						if ((key & (1 << (graph[cy][cx] - 'A'))) && !chk[cy][cx][key]) {
							q.push({ cx, cy, key });
							chk[cy][cx][key] = 1;
							++tmp;
						}
					}
					else if ((graph[cy][cx] == 1 || graph[cy][cx] == 999999)&& !chk[cy][cx][key]) {
						q.push({ cx, cy, key });
						chk[cy][cx][key] = 1;
						++tmp;
					}
				}
			}
		}
		curCnt = tmp;
		++ans;
	}
	printf("-1");
}