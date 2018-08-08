#include<cstdio>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;

int graph[10][10];
bool chk[10][10];
int nx[4] = { 0, 0, 1, -1 };
int ny[4] = { 1, -1, 0, 0 };

int zeroCnt = -3;
int res = 987654321;

int DFS(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return 0;
	if (graph[y][x] == 1 || chk[y][x])
		return 0;
	int ans;
	if (graph[y][x] == 0)
		ans = 1;
	if (graph[y][x] == 2)
		ans = 0;
	chk[y][x] = 1;
	for (int i = 0; i < 4; ++i)
		ans += DFS(x + nx[i], y + ny[i]);
	return ans;
}

void check() {
	memset(chk, 0, sizeof(chk));
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(graph[i][j] == 2)
				tmp += DFS(j, i);
		}
	}
	res = min(res, tmp);
}

void wall(int toPick) {
	if (toPick == 0) {
		check();
	}
	else {
		for (int i =  0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (graph[i][j] == 0) {
					graph[i][j] = 1;
					wall(toPick - 1);
					graph[i][j] = 0;
				}
			}	
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 0)
				++zeroCnt;
		}
	}
	int tmp = 0;
	vector<pair<int, int>> vtmp;
	wall(3);
	printf("%d", (zeroCnt - res));
}