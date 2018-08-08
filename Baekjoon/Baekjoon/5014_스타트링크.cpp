#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

bool check[1234567];

int main() {
	queue<int> q;
	int f, s, g, u, d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	q.push(s);
	check[s] = 1;
	int curCnt = 1;
	int ans = 0;
	bool hasAns = 0;
	while (q.size()) {
		int tmp = 0;
		for (int i = 0; i < curCnt; ++i) {
			int cur = q.front(); q.pop();
			if (cur == g) { hasAns = 1; break; }
			if (cur - d >= 1 && !check[cur - d]) {
				q.push(cur - d); check[cur - d] = 1;
				tmp++;
			}
			if (cur + u <= f && !check[cur + u]) {
				q.push(cur + u); check[cur + u] = 1;
				tmp++;
			}
		}
		if (hasAns)
			break;
		curCnt = tmp;
		++ans;
	}
	if (hasAns)
		printf("%d", ans);
	else
		printf("use the stairs");
}