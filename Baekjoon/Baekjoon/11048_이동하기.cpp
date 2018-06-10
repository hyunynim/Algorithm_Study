#include<cstdio>
#include<algorithm>
#include<string.h>

using namespace std;

int candy[1001][1001];
int cache[1001][1001];
int n, m;

int GetCandy(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return 0;
	else {
		int & ref = cache[y][x];
		if (ref != -1)
			return ref;
		else {
			ref = candy[y][x];
			ref += max(GetCandy(x + 1, y), max(GetCandy(x + 1, y + 1), GetCandy(x, y + 1)));
			return ref;
		}
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &candy[i][j]);
	}
	printf("%d", GetCandy(0, 0));
}