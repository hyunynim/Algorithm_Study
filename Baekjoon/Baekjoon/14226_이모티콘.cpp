#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

bool chk[1002][1002];
int go(int s) {
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	chk[1][0] = 1;
	int curCnt = 1;
	int tmp = 0;
	int ans = 0;
	while (q.size()) {
		tmp = 0;
		for (int i = 0; i < curCnt; ++i) {
			int curNum = q.front().first;
			int curCl = q.front().second;
			q.pop();
			if (curNum == s) {
				printf("%d", ans);
				return 0;
			}
			if (!chk[curNum][curNum]) {
				++tmp;
				q.push({ curNum, curNum });
				chk[curNum][curNum] = 1;
			}
			if (curNum + curCl <= 1000 && !chk[curNum + curCl][curCl]) {
				++tmp;
				q.push({ curNum + curCl, curCl });
				chk[curNum + curCl][curCl] = 1;
			}
			if (curNum > 1 && !chk[curNum - 1][curCl]) {
				++tmp;
				q.push({ curNum - 1, curCl });
				chk[curNum - 1][curCl] = 1;
			}
		}
		curCnt = tmp;
		++ans;
	}
}

int main() {
	int s;
	scanf("%d", &s);
	go(s);
}