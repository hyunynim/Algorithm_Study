#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n > k) {
		printf("%d\n1", n - k);
		return 0;
	}
	int chk[100001][2] = { 0 };
	chk[n][0] = 1;
	chk[n][1] = 0;

	queue<pair<int, int>> q;
	q.push({ n, 1 });
	int ans = 0;
	int ansCnt = 0;
	int curCnt = 1;

	while (q.size()) {
		int tmp = 0;
		bool hasAns = 0;
		queue<int> qTmp;
		for (int i = 0; i < curCnt; ++i) {
			int x = q.front().first;
			int xCnt = q.front().second;
			q.pop();

			if (x == k) {
				ansCnt = xCnt;
				hasAns = 1;
				break;
			}
			if (x > 0) {
				if (chk[x - 1][0] != 0 && chk[x - 1][1] == ans)
					chk[x - 1][0] += xCnt;
				else if (chk[x - 1][0] == 0) {
					chk[x - 1][0] = xCnt;
					chk[x - 1][1] = ans;
					qTmp.push(x - 1);
				}
			}
			if (x < 100000) {
				if (chk[x + 1][0] != 0 && chk[x + 1][1] == ans)
					chk[x + 1][0] += xCnt;
				else if (chk[x + 1][0] == 0) {
					chk[x + 1][0] = xCnt;
					chk[x + 1][1] = ans;
					qTmp.push(x + 1);
				}
			}
			if (2 * x <= 100000) {
				if (chk[2 * x][0] != 0 && chk[2 * x][1] == ans)
					chk[2 * x][0] += xCnt;
				else if (chk[2 * x][0] == 0) {
					chk[2 * x][0] = xCnt;
					chk[2 * x][1] = ans;
					qTmp.push(2 * x);
				}
			}
		}
		if (hasAns)
			break;
		curCnt = qTmp.size();
		while (qTmp.size()) {
			q.push({ qTmp.front(), chk[qTmp.front()][0] });
			qTmp.pop();
		}
		++ans;
	}
	printf("%d\n%d", ans, ansCnt);
}