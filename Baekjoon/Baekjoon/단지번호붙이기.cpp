#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool field[25][25];
bool isChecked[25][25];
int n;
int CheckField(int x, int y) {
	int res = 0;
	if (x < 0 || y < 0 || x >= n || y >= n)
		return 0;
	if (isChecked[y][x])
		return 0;
	else {
		isChecked[y][x] = 1;
		if (field[y][x]) {
			res = 1;
			res += CheckField(x + 1, y);
			res += CheckField(x - 1, y);
			res += CheckField(x, y + 1);
			res += CheckField(x, y - 1);
		}
		else
		{
			isChecked[y][x] = 1;
			return 0;
		}
	}
	return res;
}
int main() {
	memset(field, 0, sizeof(field));
	memset(isChecked, 0, sizeof(isChecked));
	scanf("%d", &n);
	vector <int> res;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &field[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int tmp = CheckField(j, i);
			if (tmp != 0)
				res.push_back(tmp);
		}
	}
	printf("%d\n", res.size());
	sort(res.begin(), res.end());
	for (int i = 0; res.begin() + i != res.end(); ++i)
		printf("%d\n", res[i]);
}