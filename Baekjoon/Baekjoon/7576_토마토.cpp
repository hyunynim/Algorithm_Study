#include<cstdio>
#include<queue>
#include<utility>

using namespace std;
int m, n;

int tomato[1000][1000];
bool CheckTomato() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (tomato[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

int main() {
	queue<pair<int, int>> search;
	scanf("%d %d", &m, &n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				search.push(make_pair(i, j));
				cnt++;
			}
		}
	}
	int x, y, day = 0;
	while (search.size()) {
		int nextCnt = cnt;
		cnt = 0;
		for (int i = 0; i < nextCnt; ++i) {
			y = search.front().first;
			x = search.front().second;
			search.pop();
			if ((0 <= x + 1 && x + 1 < m) && (0 <= y && y < n) && (tomato[y][x + 1] == 0)) {
				tomato[y][x + 1] = 1;
				search.push(make_pair(y, x + 1));
				cnt++;
			}

			if ((0 <= x - 1 && x - 1 < m) && (0 <= y && y < n) && (tomato[y][x - 1] == 0)) {
				tomato[y][x - 1] = 1;
				search.push(make_pair(y, x - 1));
				cnt++;
			}

			if ((0 <= x && x < m) && (0 <= y + 1 && y + 1 < n) && (tomato[y + 1][x] == 0)) {
				tomato[y + 1][x] = 1;
				search.push(make_pair(y + 1, x));
				cnt++;
			}

			if ((0 <= x && x < m) && (0 <= y - 1 && y - 1 < n) && (tomato[y - 1][x] == 0)) {
				tomato[y - 1][x] = 1;
				search.push(make_pair(y - 1, x));
				cnt++;
			}
		}
		++day;
	}
	if (CheckTomato())
		printf("%d", day - 1);
	else
		printf("-1");
}