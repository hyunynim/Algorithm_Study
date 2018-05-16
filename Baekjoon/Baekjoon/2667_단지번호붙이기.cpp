#include <iostream>
#include <vector>

using namespace std;

bool chk[26][26] = { 0 };

int searchApt(int ** apt, int x, int y, int n) {
	if (x < 0 || x >= n || y < 0 || y >= n || chk[x][y] || apt[x][y] == 0)
		return 0;
	else {
		int res = 0;
		if ((0 <= x - 1 && x - 1 < n) && (0 <= y - 1 && y - 1 < n)) {
			res += searchApt(apt, x - 1, y - 1, n);
			chk[x - 1][y - 1] = 1;
		}
		if ((0 <= x + 1 && x + 1 < n) && (0 <= y - 1 && y - 1 < n)) {
			res += searchApt(apt, x + 1, y - 1, n);
			chk[x + 1][y - 1] = 1;
		}
		if ((0 <= x - 1 && x - 1 < n) && (0 <= y + 1 && y + 1 < n)) {
			res += searchApt(apt, x - 1, y + 1, n);
			chk[x - 1][y + 1] = 1;
		}
		if ((0 <= x + 1 && x + 1 < n) && (0 <= y + 1 && y + 1 < n)) {
			res += searchApt(apt, x + 1, y + 1, n);
			chk[x + 1][y + 1] = 1;
		}return res;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int ** apt = new int *[n];
	vector <int> ans;
	for (int i = 0; i < n; ++i) {
		apt[i] = new int[n];
		for (int j = 0; j < n; ++j)
			scanf("%1d", &apt[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int tmp = searchApt(apt, i, j, n);
			if (tmp != 0)
				ans.push_back(tmp);
		}
	}

	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}