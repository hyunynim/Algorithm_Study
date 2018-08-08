#include<cstdio>
#include<queue>
using namespace std;
bool chk[123456];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n >= k) {
		printf("%d", (n - k));
		return 0;
	}

	queue<int> q;
	int curCnt = 1;
	int tmp;
	int ans = 0;
	q.push(n);
	chk[n] = 1;
	while (q.size()) {
		tmp = 0;
		for (int i = 0; i < curCnt; ++i) {
			int x = q.front(); q.pop();
			if (x == k) {
				printf("%d", ans);
				return 0;
			}
			if (x > 0 && !chk[x - 1]) {
				q.push(x - 1);
				chk[x - 1] = 1;
				++tmp;
			}
			if (x < 100000 && !chk[x + 1]) {
				q.push(x + 1);
				chk[x + 1] = 1;
				++tmp;
			}
			if (2 * x <= 100000 && !chk[2 * x]) {
				q.push(2 * x);
				chk[2 * x] = 1;
				++tmp;
			}
		}
		++ans;
		curCnt = tmp;
	}
}