#include<cstdio>
#include<queue>
#include<string.h>
#include<utility>
using namespace std;
int chk[10101][3];

int a, b;
void go(int s) {
	char c;
	switch (chk[s][2]) {
	case 0:
		c = 'D';
		break;
	case 1:
		c = 'S';
		break;
	case 2:
		c = 'L';
		break;
	case 3:
		c = 'R';
		break;
	}
	if (s == a) {
		return;
	}
	go(chk[s][1]);
	printf("%c", c);
}

int cmd(int a, int c) {
	int res = a;
	if (c == 0) {
		res *= 2;
		res %= 10000;
	}
	else if (c == 1) {
		res += 9999;
		res %= 10000;
	}
	else if (c == 2) {
		int num[4];
		for (int i = 3; i >= 0; --i) {
			num[i] = res % 10;
			res /= 10;
		}
		res = num[1] * 1000 + num[2] * 100 + num[3] * 10 + num[0];
	}
	else if (c == 3) {
		int num[4];
		for (int i = 3; i >= 0; --i) {
			num[i] = res % 10;
			res /= 10;
		}
		res = num[3] * 1000 + num[0] * 100 + num[1] * 10 + num[2];
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		memset(chk, 0, sizeof(chk));
		scanf("%d %d", &a, &b);
		queue<pair<int, int>> q;
		while (q.size())
			q.pop();
		q.push({ a, 0 });
		chk[a][0] = 1;
		chk[a][1] = -1;
		chk[a][2] = -1;
		int curCnt = 1;
		int tmp;
		int ans = 0;
		bool hasAns = 0;
		while (q.size()) {
			tmp = 0;
			for (int i = 0; i < curCnt; ++i) {
				int cur = q.front().first; 
				int curAns = q.front().second;
				if (cur == b) {
					go(b);
					puts("");
					hasAns = 1;
					break;
				}
				q.pop();
				
				for (int j = 0; j < 4; ++j) {
					int res = cmd(cur, j);
					if (chk[res][0] == 0) {
						q.push({ res, ans });
						chk[res][0] = 1;
						chk[res][1] = cur;
						chk[res][2] = j;
						++tmp;
					}
				}
			}
			if (hasAns)
				break;
		}
	}
}