#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
#include<functional>
#include<tuple>
using namespace std;

bool g[101][101];
bool c[101][101][101];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &g[i][j]);
		}
	}
	int ans = 987654321;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
	q.push({ 0, 0, 0 });
	c[0][0][0] = 1;
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };
	while (q.size()) {
		int cnt, x, y;
		tie(cnt, x, y) = q.top();
		if (cnt == 0 && x == 0 && y == 2) {
			ans = 12345;
		}
		if (y == m - 1 && x == n - 1) {
			printf("%d", cnt);
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			for (int j = 0; j < 2; ++j) {
				if (g[ny][nx] == j && !c[cnt + j][ny][nx]) {
					q.push({ cnt + j, nx, ny });
					c[cnt + j][ny][nx] = 1;
				}
			}
		}
	}
}