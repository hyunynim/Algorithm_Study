#include<cstdio>
#include<queue>
#include<tuple>

using namespace std;

bool chk[1002][1002];
bool graph[1002][1002];
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
	int curCnt = 0;
	int tmp;
	queue<tuple<int, int>> q;
	for (int i = 0; i < m; ++i) {
		if (graph[0][i] == 0) {
			q.push({ i, 0 });
			chk[0][i] = 1;
			curCnt++;
		}
	}
	while (q.size()) {
		int x, y, cnt;
		tmp = 0;
		for (int TC = 0; TC < curCnt; ++TC) {
			tie(x, y) = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				if (x + nx[i] < 0 || y + ny[i] < 0 || x + nx[i] >= m || y + ny[i] >= n)
					continue;
				else if (!graph[y + ny[i]][x + nx[i]]) {
					if (!chk[y + ny[i]][x + nx[i]]) {
						q.push({ x + nx[i], y + ny[i]});
						chk[y + ny[i]][x + nx[i]] = 1;
						++tmp;
					}
				}
			}
		}
		curCnt = tmp;
	}
	for (int i = 0; i < m; ++i) {
		if (chk[n - 1][i]) {
			printf("YES");
			return 0;
		}
	}

	printf("NO");
}