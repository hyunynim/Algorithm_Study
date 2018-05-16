#include<cstdio>
#include<queue>
#include<utility>

using namespace std;
int m, n, h;

int tomato[100][100][100];
bool CheckTomato() {
	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (tomato[k][i][j] == 0)
					return 0;
			}
		}
	}
	return 1;
}

int main() {
	queue<pair<pair<int, int>, int>> search;
	scanf("%d %d %d", &m, &n, &h);
	int cnt = 0;
	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &tomato[k][i][j]);
				if (tomato[k][i][j] == 1) {
					search.push(make_pair(make_pair(k, i), j));
					cnt++;
				}
			}
		}
	}
	int x, y, z, day = 0;
	while (search.size()) {
		int nextCnt = cnt;
		cnt = 0;
		for (int i = 0; i < nextCnt; ++i) {
			z = search.front().first.first;
			y = search.front().first.second;
			x = search.front().second;
			search.pop();
			if ((0 <= x + 1 && x + 1 < m) && (0 <= y && y < n) && (0 <= z && z < h) && (tomato[z][y][x + 1] == 0)) {
				tomato[z][y][x + 1] = 1;
				search.push(make_pair(make_pair(z, y), x + 1));
				cnt++;
			}
			if ((0 <= x - 1 && x - 1 < m) && (0 <= y && y < n) && (0 <= z && z < h) && (tomato[z][y][x - 1] == 0)) {
				tomato[z][y][x - 1] = 1;
				search.push(make_pair(make_pair(z, y), x - 1));
				cnt++;
			}
			if ((0 <= x && x < m) && (0 <= y + 1 && y + 1 < n) && (0 <= z && z < h) && (tomato[z][y + 1][x] == 0)) {
				tomato[z][y + 1][x] = 1;
				search.push(make_pair(make_pair(z, y + 1), x));
				cnt++;
			}
			if ((0 <= x && x < m) && (0 <= y - 1 && y - 1 < n) && (0 <= z && z < h) && (tomato[z][y - 1][x] == 0)) {
				tomato[z][y - 1][x] = 1;
				search.push(make_pair(make_pair(z, y - 1), x));
				cnt++;
			}
			if ((0 <= x && x < m) && (0 <= y && y < n) && (0 <= z + 1 && z + 1 < h) && (tomato[z + 1][y][x] == 0)) {
				tomato[z + 1][y][x] = 1;
				search.push(make_pair(make_pair(z + 1, y), x));
				cnt++;
			}
			if ((0 <= x && x < m) && (0 <= y && y < n) && (0 <= z - 1 && z - 1 < h) && (tomato[z - 1][y][x] == 0)) {
				tomato[z - 1][y][x] = 1;
				search.push(make_pair(make_pair(z - 1, y), x));
				cnt++;
			}
		}
		++day;
	}
	if (CheckTomato())
		printf("%d", day - 1);
	else
		printf("-1");



	/*comment*/
	//오타 있었음