#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n + 1), rank(n + 1, 1) {
		for (int i = 0; i <= n; ++i)
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


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	DisjointSet ds(n);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		if (a)
			printf("%s\n", ds.find(b) == ds.find(c) ? "YES" : "NO");
		else
			ds.merge(b, c);
	}
}

/*comment*/
//b,c에 0도 들어올 수 있음