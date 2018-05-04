#include<cstdio>
#include<queue>
#include<utility>

using namespace std;

bool g[100][100] = { 0 };
bool isChk[100][100] = { 0 };
bool isContinue = 1;
int n, m;
int FindPath(queue<pair<int, int>> & path, int cnt) {
	int nextCnt = 0;
	int y, x;
	for (int i = 0; i < cnt; ++i) {
		y = path.front().first;
		x = path.front().second;
		path.pop();
		isChk[y][x] = 1;
		if (!isChk[y + 1][x] && g[y + 1][x] && y + 1 < n) {
			if (y + 1 == n - 1 && x == m - 1)
				return -1;
			isChk[y+1][x] = 1;
			path.push(make_pair(y + 1, x));
			nextCnt++;
		}
		if (!isChk[y - 1][x] && g[y - 1][x] && y > 0) {
			if (y - 1 == n - 1 && x == m - 1)
				return -1;
			isChk[y-1][x] = 1;
			path.push(make_pair(y - 1, x));
			nextCnt++;
		}
		if (!isChk[y][x - 1] && g[y][x - 1] && x > 0) {
			if (y == n - 1 && x - 1 == m - 1)
				return -1;
			isChk[y][x-1] = 1;
			path.push(make_pair(y, x - 1));
			nextCnt++;
		}
		if (!isChk[y][x + 1] && g[y][x + 1] && x + 1 < m) {
			if (y == n - 1 && x + 1 == m - 1)
				return -1;
			isChk[y][x+1] = 1;
			path.push(make_pair(y, x + 1));
			nextCnt++;
		}
	}
	return nextCnt;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &g[i][j]);
		}
	}
	queue<pair<int, int>> path;
	path.push(make_pair(0, 0));
	int k = 1;
	int tmp = 1;
	while (tmp != -1) {
		tmp = FindPath(path, tmp);
		++k;
	}
	printf("%d", k);
}

/*comment*/
//메모리초과
//pop할때 isChk를 바꾸는게 아니라 처음 push 할 때 isChk를 바꾸게 함