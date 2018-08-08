#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional>
#include<string>
#include<queue>
#include<stack>
#include<string.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
vector<int> adj[101010];
vector<int> sing;
vector<ll> sc;
vector<int> ans;
vector<int> child;
vector<int> cnt;
bool chk[100001];

int n, k, j;

int getChild(int s) {
	chk[s] = 1;
	child[s] = 1;
	for (int i = 0; i < adj[s].size(); ++i) {
		if (!chk[adj[s][i]])
			child[s] += getChild(adj[s][i]);
	}
	return child[s];
}

void DFS(int s, int sco, int t) {
	chk[s] = 1;
	sc[sing[s]] += sco;
	if (sc[sing[s]] / cnt[sing[s]] >= j) {
		if (ans[sing[s]] == 0)
			ans[sing[s]] = t;
		else
			ans[sing[s]] = min(ans[sing[s]], t);
	}
	for (int i = 0; i < adj[s].size(); ++i) {
		if (!chk[adj[s][i]]) {
			DFS(adj[s][i], sco, t);
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &j);
	for (int i = 0; i < n - 1; ++i) {
		int b, w;
		scanf("%d", &b);
		adj[b].push_back(i + 2);
	}
	sing.resize(n+1);
	sc.resize(n+1);
	ans.resize(n + 1);
	child.resize(n + 1);
	cnt.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &sing[i]);
		cnt[sing[i]]++;
	}
	getChild(1);
	vector<tuple<int, int, int>> col;
	int t, p, s;
	for (int i = 0; i < k; ++i) {
		scanf("%d %d %d", &t, &p, &s);
		col.push_back({ t, p, s });
	}
	sort(col.begin(), col.end());
	for (int i = 0; i < col.size(); ++i) {
		tie(t, p, s) = col[i];
		sc[sing[s]] += s / child[p];
		DFS(p, s / child[p], t);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[sing[i]] ? ans[sing[i]] : -1);
	}
}
