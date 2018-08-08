#include<cstdio>
#include<queue>
#include<tuple>

using namespace std;

bool chk[1000][1000][2];
bool graph[1000][1000];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &graph[i][j]);
		}
	}
	int nx[4] = { 0, 0, 1, -1 };
	int ny[4] = { 1, -1, 0, 0 };
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	chk[0][0][0] = 1;
	int ans = 0;
	int curCnt = 1;
	int tmp;
	while (q.size()) {
		int x, y, cnt;
		tmp = 0;
		for (int TC = 0; TC < curCnt; ++TC) {
			tie(x, y, cnt) = q.front();
			if (x == m - 1 && y == n - 1) {
				printf("%d", ans + 1);
				return 0;
			}
			q.pop();
			for (int i = 0; i < 4; ++i) {
				if (x + nx[i] < 0 || y + ny[i] < 0 || x + nx[i] >= m || y + ny[i] >= n)
					continue;
				else {
					if (cnt == 0 && graph[y + ny[i]][x + nx[i]]) {
						if (!chk[y + ny[i]][x + nx[i]][1]) {
							q.push({ x + nx[i], y + ny[i], 1 });
							chk[y + ny[i]][x + nx[i]][1] = 1;
							++tmp;
						}
					}
					else if(!graph[y + ny[i]][x + nx[i]]){
						if (!chk[y + ny[i]][x + nx[i]][cnt]) {
							q.push({ x + nx[i], y + ny[i], cnt });
							chk[y + ny[i]][x + nx[i]][cnt] = 1;
							++tmp;
						}
					}
				}
			}
		}
		curCnt = tmp;
		++ans;
	}
	printf("-1");
}