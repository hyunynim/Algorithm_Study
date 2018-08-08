#include<cstdio>
#include<queue>
using namespace std;
bool chk[123456];
int main() {
	int n, k, A, B;
	scanf("%d %d %d %d", &A, &B, &n, &k);

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
			if (A * x <= 100000 && !chk[A * x]) {
				q.push(A * x);
				chk[A * x] = 1;
				++tmp;
			}
			if (B * x <= 100000 && !chk[B * x]) {
				q.push(B * x);
				chk[B * x] = 1;
				++tmp;
			}
			if (x - A >= 0 && !chk[x - A]) {
				q.push(x - A);
				chk[x - A] = 1;
				++tmp;
			}
			if (x + A <= 100000 && !chk[x + A]) {
				q.push(x + A);
				chk[x + A] = 1;
				++tmp;
			}
			if (x - B >= 0 && !chk[x - B]) {
				q.push(x - B);
				chk[x - B] = 1;
				++tmp;
			}
			if (x + B <= 100000 && !chk[x + B]) {
				q.push(x + B);
				chk[x + B] = 1;
				++tmp;
			}
		}
		++ans;
		curCnt = tmp;
	}
}