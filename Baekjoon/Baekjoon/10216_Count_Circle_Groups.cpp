#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<string.h>

using namespace std;
vector < pair<pair<int, int>, int>> seq;
bool chk[3210];
int n, x, y, r;

bool Dist(int v1, int v2) {
	int xx = (seq[v1].first.first - seq[v2].first.first)*(seq[v1].first.first - seq[v2].first.first);
	int yy = (seq[v1].first.second - seq[v2].first.second)*(seq[v1].first.second - seq[v2].first.second);
	int rr = (seq[v1].second + seq[v2].second) * (seq[v1].second + seq[v2].second);
	return xx + yy <= rr;
}

bool DFS(int v) {
	if (chk[v])
		return 0;
	chk[v] = 1;
	for (int i = 0; i < n; ++i) {
		if (i == v)
			continue;
		if (!chk[i] && Dist(v, i))
			DFS(i);
	}
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		memset(chk, 0, sizeof(chk));
		seq.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d", &x, &y, &r);
			seq.push_back({ {x, y}, r });
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (DFS(i)) ans++;
		printf("%d\n", ans);
	}
}