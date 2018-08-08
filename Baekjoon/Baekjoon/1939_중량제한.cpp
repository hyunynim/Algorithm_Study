#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<string.h>
using namespace std;

vector<pair<int ,int>> adj[12345];
int n, m, s, e;
int minW = 1010101010, maxW = -1;
bool chk[10101];

bool DFS(int st, int w) {
	if (st == e)
		return 1;
	if (chk[st])
		return 0;
	chk[st] = 1;
	for (int i = 0; i < adj[st].size(); ++i) {
		if (adj[st][i].first >= w && DFS(adj[st][i].second, w))
			return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back({ w, b });
		adj[b].push_back({ w, a });
		minW = min(minW, w);
		maxW = max(maxW, w);
	}
	scanf("%d %d", &s, &e);
	int ans = 0;
	while (minW <= maxW) {
		memset(chk, 0, sizeof(chk));
		int sw = (minW + maxW) / 2;
		if (DFS(s, sw)) {
			ans = sw;
			minW = sw + 1;
		}
		else 
			maxW = sw - 1;
	}
	printf("%d", ans);
}