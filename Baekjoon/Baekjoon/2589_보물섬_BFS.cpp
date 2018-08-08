#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
#include<string.h>
using namespace std;

bool chk[123][123];
bool graph[123][123];
int h, w;

int BFS(int sy, int sx) {
	if (!graph[sy][sx])
		return 0;
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	int curCnt = 1;
	chk[sy][sx] = 1;
	int ans = 0;
	while (q.size()) {
		int tmp = 0;
		for (int i = 0; i < curCnt; ++i) {
			pair<int, int> cur = q.front(); q.pop();
			int x = cur.second;
			int y = cur.first;
			if (x > 0 && !chk[y][x - 1] && graph[y][x-1]) {
				chk[y][x - 1] = 1;
				q.push({ y, x - 1 });
				++tmp;
			}
			if (x < w - 1 && !chk[y][x + 1] && graph[y][x + 1]) {
				chk[y][x + 1] = 1;
				q.push({ y, x + 1 });
				++tmp;
			}
			if (y > 0 && !chk[y - 1][x] && graph[y - 1][x]) {
				chk[y - 1][x] = 1;
				q.push({ y - 1, x });
				++tmp;
			}
			if (y < h - 1 && !chk[y + 1][x] && graph[y + 1][x]) {
				chk[y + 1][x] = 1;
				q.push({ y + 1, x });
				++tmp;
			}
		}
		curCnt = tmp;
		++ans;
	}
	return ans;
}

int main() {
	char msg[1234];
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) {
		scanf("%s", msg);
		for (int j = 0; j < w; ++j)
			if (msg[j] == 'L') graph[i][j] = 1;
	}
	int ans = 0;
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j) {
			int tmp = BFS(i, j);
			ans = max(ans, tmp);
			if (tmp) 
				memset(chk, 0, sizeof(chk));
		}
	}
	printf("%d", ans ? ans - 1 : 0);
}