#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<tuple>
using namespace std;

typedef long long ll;

bool map[123][123];
int sz[123][123];
int n, m;

int cnt(int x, int y) {
	if (!map[y][x]) 
		return 0;
	
	int cnt = 0;
	for (int i = 1; x - i >= 0 && x + i < m && y - i >= 0 && y + i < n; ++i, cnt = i) {
		if (map[y - i][x] && map[y + i][x] && map[y][x - i] && map[y][x + i])
			continue;
		return cnt - 1;
	}
	return cnt - 1;
}

bool erase(int x, int y, int cnt) {
	map[y][x] = 0;
	for (int i = 1; i <= cnt; ++i) {
		map[y - i][x] = 0;
		map[y + i][x] = 0;
		map[y][x - i] = 0;
		map[y][x + i] = 0;
	}
	return 1;
}

int main() {
	int fail = 0;
	scanf("%d %d", &n, &m);
	char msg[1234];
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		for (int j = 0; j < m; ++j) {
			if (msg[j] == '*') {
				map[i][j] = 1;
				++fail;
			}
		}
	}
	if (fail == 0) {
		printf("0");
	}
	vector<tuple<int, int, int>> ans;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			int c = cnt(j, i);
			if (c > 0)
				ans.push_back({ j, i, c });
		}
	}
	for (int i = 0; i < ans.size(); ++i) {
		int x, y, c;
		tie(x, y, c) = ans[i];
		erase(x, y, c);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}
	for (int i = 0; i < ans.size(); ++i) {
		int x, y, c;
		tie(x, y, c) = ans[i];
		printf("%d %d %d\n", y + 1, x + 1, c);
	}
}