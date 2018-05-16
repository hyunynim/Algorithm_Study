#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool arr[101][101] = { 0 };
bool isChecked[101][101];
int m, n, k;

void FillArr(int sx, int sy, int ex, int ey) {
	for (int i = sy; i < ey; ++i) {
		for (int j = sx; j < ex; ++j)
			arr[i][j] = 0;
	}
}
int CheckField(int x, int y) {
	int res = 0;
	if (x < 0 || y < 0 || x >= m || y >= n)
		return 0;
	if (isChecked[y][x])
		return 0;
	else {
		isChecked[y][x] = 1;
		if (arr[y][x]) {
			res = 1;
			res += CheckField(x + 1, y);
			res += CheckField(x - 1, y);
			res += CheckField(x, y + 1);
			res += CheckField(x, y - 1);
		}
		else
		{
			isChecked[y][x];
			return 0;
		}
	}
	return res;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			arr[i][j] = 1;
	}
	int sx, sy, ex, ey;
	for (int i = 0; i < k; ++i) {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		FillArr(sx, sy, ex, ey);
	}

	int res = 0;
	vector<int> resSize;
	for (int yNext = 0; yNext < n; ++yNext) {
		for (int xNext = 0; xNext < m; ++xNext) {
			int tmp = CheckField(xNext, yNext);
			if (tmp) {
				resSize.push_back(tmp);
				res++;
			}
		}
	}
	sort(resSize.begin(), resSize.end());
	printf("%d\n", res);
	for (int i = 0; i < resSize.size(); ++i)
		printf("%d ", resSize[i]);
}