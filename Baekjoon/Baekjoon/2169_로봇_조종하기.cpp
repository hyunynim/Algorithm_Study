#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define INF -(ll)1e15

int n, m;
int board[1001][1001];
ll cache[3][1001][1001];
bool chk[1001][1001];
int nx[3] = { 1, -1, 0 };
int ny[3] = { 0, 0, 1 };
int np[3] = { 0, 1, 2 };

ll FindMax(int x, int y, int prev) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return INF;
	ll & res = cache[prev][y][x];
	if (x == m - 1 && y == n - 1)
		return board[y][x];
	if (chk[y][x])
		return INF;
	if (res >= -10000000)
		return res;
	else {
		res = board[y][x];
		chk[y][x] = 1;
		ll tmp = INF;
		for (int i = 0; i < 3; ++i)
			tmp = max(tmp, FindMax(x + nx[i], y + ny[i], np[i]));
		chk[y][x] = 0;
		res += tmp;
		return res;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &board[i][j]);
			for(int k = 0; k<3; ++k)
				cache[k][i][j] = INF;
		}
	}
	printf("%lld", FindMax(0, 0, 0));
}