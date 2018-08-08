#include<cstdio>
#include<queue>
#include<utility>

using namespace std;

bool chk[101010];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n >= k) {
		printf("%d", n - k);
		return 0;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, n });
	chk[n] = 1;
	int curCnt = 1;
	int tmp;
	int ans = 10101010;
	while (q.size()) {
		tmp = 0;
		bool hasAns = 0;
		int x = q.top().second;
		int xAns = q.top().first;
		q.pop();
		if (x == k) {
			printf("%d", xAns);
			return 0;
		}
		if (2 * x <= 100000 && !chk[2 * x]) {
			q.push({ xAns, 2 * x });
			chk[2 * x] = 1;
			++tmp;
		}
		if (x > 0 && !chk[x - 1]) {
			q.push({ xAns + 1, x - 1 });
			chk[x - 1] = 1;
			++tmp;
		}
		if (x < 100000 && !chk[x + 1]) {
			q.push({ xAns + 1, x + 1 });
			chk[x + 1] = 1;
			++tmp;
		}
		curCnt = tmp;
	}
}