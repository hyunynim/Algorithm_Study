#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;

const int MAXL = 305;
int dist[MAXL][MAXL];

int ABS(int a) {
	return a > 0 ? a : -a;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int l, x1, y1, x2, y2;
		scanf("%d %d %d %d %d", &l, &x1, &y1, &x2, &y2);
		memset(dist, -1, sizeof(dist));
		dist[x1][y1] = 0;
		queue<pair<int, int>> q;
		q.push(make_pair(x1, y1));
		while (!q.empty() && !(q.front().first == x2 && q.front().second == y2)) {
			pair<int, int> cur = q.front();
			q.pop();
			int d = dist[cur.first][cur.second] + 1;
			for (int i = -2; i <= 2; ++i) {
				if (!i) continue;
				for (int j = -2; j <= 2; ++j) {
					if (ABS(i) == ABS(j) || !j) continue;
					int nx = cur.first + i;
					int ny = cur.second + j;
					if (0 <= nx && nx < l && 0 <= ny && ny < l && dist[nx][ny] == -1) {
						dist[nx][ny] = d;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		printf("%d\n", dist[x2][y2]);
	}
}
/*comment*/
//¿ÖÆ²·ÈÀ»±î
//300 0 0 299 299 ´äÀÌ ¾È³ª¿È