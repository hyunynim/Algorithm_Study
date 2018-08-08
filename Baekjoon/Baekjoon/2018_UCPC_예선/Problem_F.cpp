#include<vector>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define MAX_V 200001
typedef long long ll;
#define MOD (ll)1e9 + 7
using namespace std;

vector < pair<int, int> > adj[MAX_V];
vector<int> color;
int V, q, c;
bool chk[MAX_V];

ll dfs(int start, int col) {
	chk[start] = 1;
	ll ans = 0;
	if (color[start] <= col)
		ans = 1;
	for (int i = 0; i < adj[start].size(); ++i) {
		int next = adj[start][i].first;
		if (!chk[next]) {
			ans += dfs(next, col);
			ans %= MOD;
		}
	}
	return ans;
}

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int DFind(int u) {
		if (u == parent[u]) return u;
		return parent[u] = DFind(parent[u]);
	}

	void DMerge(int u, int v) {
		u = DFind(u); v = DFind(v);

		if (u == v) return;

		if (rank[u] > rank[v]) swap(u, v);

		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};

int Kruskal(vector<pair<int, int>> & picked) {
	int res = 0;
	picked.clear();
	vector<pair<int, pair<int, int>>> edges;
	for (int u = 0; u < V; ++u) {
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}
	sort(edges.begin(), edges.end());
	DisjointSet sets(V);
	for (int i = 0; i < edges.size(); ++i) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (sets.DFind(u) == sets.DFind(v)) continue;
		sets.DMerge(u, v);
		picked.push_back(make_pair(u, v));
		res += cost;
	}
	return res;
}

int main() {
	int a, b;
	scanf("%d %d %d", &V, &q, &c);
	color.resize(V);
	for (int i = 0; i < V; ++i)
		scanf("%d", &color[i]);
	for (int i = 0; i < V - 1; ++i) {
		scanf("%d %d", &a, &b);
		adj[a - 1].push_back(make_pair(b - 1, 1));
		adj[b - 1].push_back(make_pair(a - 1, 1));
	}
	vector<pair<int, int>> vtmp; Kruskal(vtmp);
	for (int i = 0; i < V; ++i) {
		if (adj[i].size())
			adj[i].clear();
	}
	for (int i = 0; i < vtmp.size(); ++i) {
		adj[vtmp[i].first].push_back({ vtmp[i].second, 1 });
	}
	ll ans = 0;
	for (int i = 0; i < q; ++i) {
		memset(chk, 0, sizeof(chk));
		scanf("%d %d", &a, &b);
		ans += dfs(a - 1, b);
		ans %= MOD;
	}
	printf("%lld", ans);

}