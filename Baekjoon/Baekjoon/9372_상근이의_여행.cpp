#include<vector>
#include<cstdio>
#include<algorithm>
#define MAX_V 10000

using namespace std;

vector < pair<int, int> > adj[MAX_V];
int V, E;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u); v = find(v);

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
		if (sets.find(u) == sets.find(v)) continue;
		sets.merge(u, v);
		picked.push_back(make_pair(u, v));
		res += cost;
	}
	return res;
}

int main() {
	int a, b, c, t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; ++i) {
			scanf("%d %d", &a, &b);
			c = 1;
			adj[a - 1].push_back(make_pair(b - 1, c));
			adj[b - 1].push_back(make_pair(a - 1, c));
		}
		vector<pair<int, int>> vtmp;
		printf("%d\n", Kruskal(vtmp));
		for (int i = 0; i < MAX_V; ++i)
			adj[i].clear();
	}
}

/*comment*/
//vector 초기화 안해줌