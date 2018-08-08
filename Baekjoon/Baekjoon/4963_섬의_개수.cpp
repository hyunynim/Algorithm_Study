#include<cstdio>
#include<string.h>
bool map_[55][55];
bool chk[55][55];
const int nx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int ny[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int w, h, ans;

int DFS(int x, int y) {
	if (x < 0 || y < 0 || y >= h || x >= w)
		return 0;
	if (chk[y][x] || !map_[y][x])
		return 0;
	int ans = 1;
	chk[y][x] = 1;
	for (int i = 0; i < 8; ++i)
		ans += DFS(x + nx[i], y + ny[i]);
	return ans;
}

int main() {
	
	while(1){
		ans = 0;
		memset(chk, 0, sizeof(chk));
		memset(map_, 0, sizeof(map_));
		scanf("%d %d", &w, &h);
		if (w == 0 && h == w)
			return 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				scanf("%d", &map_[i][j]);
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (DFS(j, i))
					++ans;
			}
		}
		printf("%d\n", ans);
	}
}