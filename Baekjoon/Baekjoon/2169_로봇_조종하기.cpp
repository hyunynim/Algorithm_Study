#include<cstdio>
#include<string.h>
#include<algorithm>
#define INT_INF 98765432LL
using namespace std;
typedef long long ll;

int n, m;
int board[1001][1001] = { 0 };
ll cache[1001][1001];

ll FindMax(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return -INT_INF;
	ll & res = cache[y][x];
	if (res != -1)
		return res;
	else {
		res = board[y][x];
		if (y == n - 1 && x == m - 1)
			return res;
		res += max(FindMax(x + 1, y), max(FindMax(x, y + 1), FindMax(x - 1, y)));
		return res;
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &board[i][j]);
		}
	}
	printf("%lld", FindMax(0, 0));
}

/*comment*/
//중복방문 안하게 고쳐야함