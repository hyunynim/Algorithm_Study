#include<cstdio>
#include<queue>
using namespace std;
bool chk[123456];
int v[101010][2];
int n, k;

void go(int s) {
	if (s == n) {
		printf("%d ", n);
		return;
	}
	go(v[s][0]);
	printf("%d ", s);
}

int main() {
	scanf("%d %d", &n, &k);
	if (n >= k) {
		printf("%d\n", (n - k));
		for (int i = n; i >= k; --i)
			printf("%d ", i);
		return 0;
	}
	for (int i = 0; i < 101010; ++i) {
		for (int j = 0; j < 2; ++j)
			v[i][j] = 191919;
	}

	queue<int> q;
	int curCnt = 1;
	int tmp;
	int ans = 0;
	q.push(n);
	chk[n] = 1;
	v[n][0] = -1;
	while (q.size()) {
		tmp = 0;
		for (int i = 0; i < curCnt; ++i) {
			int x = q.front(); q.pop();
			if (x == k) {
				printf("%d\n", ans);
				go(k);
				return 0;
			}
			if (x > 0 && !chk[x - 1]) {
				q.push(x - 1);
				chk[x - 1] = 1;
				if (v[x - 1][1] > ans) {
					v[x - 1][0] = x;
					v[x - 1][1] = ans;
				}
				++tmp;
			}
			if (x < 100000 && !chk[x + 1]) {
				q.push(x + 1);
				chk[x + 1] = 1;
				if (v[x + 1][1] > ans) {
					v[x + 1][0] = x;
					v[x + 1][1] = ans;
				}
				++tmp;
			}
			if (2 * x <= 100000 && !chk[2 * x]) {
				q.push(2 * x);
				chk[2 * x] = 1;
				if (v[2 * x][1] > ans) {
					v[2 * x][0] = x;
					v[2 * x][1] = ans;
				}
				++tmp;
			}
		}
		++ans;
		curCnt = tmp;
	}
}