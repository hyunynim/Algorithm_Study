#include<cstdio>

int pic[2][101][101];

bool chk[2][101][101];
int n;

int nx[4] = { 0, 0, 1, -1 };
int ny[4] = { 1, -1, 0, 0 };

int DFS(int x, int y, int ind, int c) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return 0;
	if (chk[ind][y][x] || pic[ind][y][x] != c)
		return 0;
	int ans = 1;
	chk[ind][y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		ans += DFS(x + nx[i], y + ny[i], ind, c);
	}
	return ans;
}

int main() {
	char msg[1234];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		for (int j = 0; j < n; ++j) {
			if (msg[j] == 'R') {
				pic[0][i][j] = pic[1][i][j] = 0;
			}
			else if (msg[j] == 'G') {
				pic[0][i][j] = 1;
				pic[1][i][j] = 0;
			}
			else if (msg[j] == 'B') {
				pic[0][i][j] = 2;
				pic[1][i][j] = 1;
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (DFS(j, i, 0, k))
					++ans1;
				if (DFS(j, i, 1, k))
					++ans2;
			}
		}
	}
	printf("%d %d", ans1, ans2);
}