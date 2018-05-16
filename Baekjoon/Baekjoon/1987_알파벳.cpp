#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
char apb[25][25];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int r, c;
int findAns(vector<int>& m, int x, int y) {
	int ans = 0;
	for (int i = 0; i<4; ++i) {
		if (x + dx[i]>0 && x + dx[i] <= r && y + dy[i]>0 && y + dy[i] <= c) {
			if (!m[apb[x + dx[i]][y + dy[i]] - 'A']) {
				m[apb[x + dx[i]][y + dy[i]] - 'A'] = 1;
				ans = max(ans, findAns(m, x + dx[i], y + dy[i]));
				m[apb[x + dx[i]][y + dy[i]] - 'A'] = 0;
			}
		}
	}
	return 1 + ans;
}
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; ++i) {
		scanf("%s", apb[i] + 1);
	}
	vector<int> m(30, 0);
	m[apb[1][1] - 'A'] = 1;
	printf("%d", findAns(m, 1, 1));
}