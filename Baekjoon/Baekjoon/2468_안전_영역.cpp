#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;
int chk[101][101];
int graph[101][101];
int n;
int nx[4] = { 0, 0, 1, -1 };
int ny[4] = { 1, -1, 0, 0, };

int DFS(int y, int x, int h) {
	if (y < 0 || x < 0 || y >= n || x >= n)
		return 0;
	
	int & ans = chk[y][x];
	if(ans != -1)
		return ans;
	if (graph[y][x] <= h)
		ans = 0;
	else {
		ans = 1;
		for (int i = 0; i < 4; ++i)
			ans += DFS(y + ny[i], x + nx[i], h);
	}
	return ans;
}

int main() {
	int maxH = 0, minH = (int)1e9;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &graph[i][j]);
			maxH = max(maxH, graph[i][j]);
			minH = min(minH, graph[i][j]);
		}
	}
	int ans = 0;
	for (int i = minH - 1; i < maxH; ++i) {
		memset(chk, -1, sizeof(chk));
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (chk[j][k] == -1 && DFS(j, k, i))
					++cnt;
			}
		}
		printf("i: %d, cnt: %d\n", i, cnt);
		ans = max(ans, cnt);
	}
	printf("%d", ans);
}