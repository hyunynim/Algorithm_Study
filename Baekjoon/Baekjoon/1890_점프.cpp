#include<cstdio>
#include<string.h>

int board[101][101] = { 0 };
long long cache[101][101];
int n;

long long JumpTo(int x, int y) {
	if (x >= n || y >= n)
		return 0;
	if (x == n - 1 && y == n - 1)
		return 1;
	long long & res = cache[y][x];
	if (res != -1)
		return res;
	else {
		res = 0;
		res += JumpTo(x + board[y][x], y);
		res += JumpTo(x, y + board[y][x]);
		return res;
	}
}


int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &board[i][j]);
		}
	}
	printf("%lld", JumpTo(0, 0));
}

/*comment*/
//overflow 생각 안함