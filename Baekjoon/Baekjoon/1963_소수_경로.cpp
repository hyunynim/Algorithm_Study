#include<cstdio>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

int sieve[12345] = { -1, -1 };
bool chk[1234];
vector<int> edge[1070];
vector<int> prime;
int ABS(int a) { return a > 0 ? a : -a; }

bool oneDig(int a, int b) {
	int cnt = 0;
	while (a > 0) {
		if (a % 10 != b % 10)
			++cnt;
		a /= 10;
		b /= 10;
	}
	return cnt == 1 ? 1 : 0;
}

int main() {
	int cnt = 0;
	for (int i = 2; i <= 10000; ++i) {
		if (sieve[i] == -1)
			continue;
		if (i >= 1000) {
			sieve[i] = cnt++;
			prime.push_back(i);
		}
		for (int j = i * i; j <= 10000; j += i)
			sieve[j] = -1;
	}

	for (int i = 0; i < prime.size(); ++i) {
		for (int j = 0; j < prime.size(); ++j) {
			if (i == j)
				continue;
			if (oneDig(prime[i], prime[j])) {
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
	}
	int t;
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == b) { printf("0\n"); continue; }
		memset(chk, 0, sizeof(chk));
		queue<int> q;
		q.push(sieve[a]);
		chk[sieve[a]] = 1;
		int curCnt = 1;
		int ans = 0;
		bool hasAns = 0;
		int tmp;
		while (q.size()) {
			tmp = 0;
			for (int j = 0; j < curCnt; ++j) {
				int cur = q.front(); q.pop();
				chk[cur] = 1;
				for (int i = 0; i < edge[cur].size(); ++i) {
					if (!chk[edge[cur][i]]) {
						if (prime[edge[cur][i]] == b) { hasAns = 1; break; }
						q.push(edge[cur][i]); chk[edge[cur][i]] = 1;
						++tmp;
					}
				}
			}
			curCnt = tmp;
			++ans;
			if (hasAns)
				break;
		}
		if (hasAns)
			printf("%d\n", ans);
		else
			puts("Impossible");
	}
}