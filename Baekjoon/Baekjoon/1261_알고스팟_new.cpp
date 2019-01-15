#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> T;
bool g[101][101];
int c[101][101];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &g[i][j]);
            c[i][j] = 101010;
		}
	}
	priority_queue<T, vector<T>, greater<T>> q;
	q.push({ 0, 0, 0 });
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };
	while (q.size()) {
		int cnt, x, y;
		tie(cnt, x, y) = q.top();
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
				if (g[ny][nx] == j && cnt + j < c[ny][nx]) {
					q.push({ cnt + j, nx, ny });
					c[ny][nx] = cnt + j;
				}
			}
		}
	}
}
