#include<cstdio>

bool banner[251][251];
bool isChecked[251][251] = { 0 };

int m, n;

int checkBanner(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;
	else {
		if (isChecked[y][x])
			return 0;
		else {
			isChecked[y][x] = 1;
			if (banner[y][x]) {
				int res = 1;
				res += checkBanner(x + 1, y);
				res += checkBanner(x - 1, y);
				res += checkBanner(x, y + 1);
				res += checkBanner(x, y - 1);
				res += checkBanner(x + 1, y + 1);
				res += checkBanner(x - 1, y + 1);
				res += checkBanner(x + 1, y - 1);
				res += checkBanner(x - 1, y - 1);
				return res;
			}
			return 0;
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &banner[i][j]);
	}

	int res = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (checkBanner(j, i))
				++res;
		}
	}
		printf("%d", res);
}