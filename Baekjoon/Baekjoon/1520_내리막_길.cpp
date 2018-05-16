#include<cstdio>
#include<string.h>

int map[501][501] = { 0 };
int n, m;
int cache[501][501];

int Find(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;
	if (x == n - 1 && y == m - 1)
		return 1;
	else {
		int & ref = cache[y][x];
		if (ref != -1)
			return ref;

		ref = 0;
		if(map[y][x + 1] < map[y][x])
		ref += Find(x + 1, y);
		if (map[y][x - 1] < map[y][x])
		ref += Find(x - 1, y);
		if (map[y + 1][x] < map[y][x])
		ref += Find(x, y + 1);
		if (map[y - 1][x] < map[y][x])
		ref += Find(x, y - 1);
		
		return ref;
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", Find(0, 0));
}