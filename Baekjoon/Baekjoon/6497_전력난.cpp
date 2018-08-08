#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<utility>
#include<functional>
#include<queue>
#include<string.h>
#define MAX_SIZE 200001

using namespace std;

typedef pair<int, int> P;
vector<P> adj[MAX_SIZE];
bool chk[MAX_SIZE];
struct DISJOINT {
	vector<int> p;
	vector<int> sz;
	DISJOINT() {
		p.resize(MAX_SIZE);
		sz.resize(MAX_SIZE);
		for (int i = 0; i < MAX_SIZE; ++i) {
			p[i] = i;
			sz[i] = 1;
		}
	}
	int Find(int x) {
		if (x == p[x])
			return  x;
		else
			return p[x] = Find(p[x]);
	}
	int Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x != y) {
			p[y] = x;
			sz[y] = sz[x] += sz[y];
		}
		return sz[x];
	}
};

int main() {
	while (1) {
		int n, m;
		int tot = 0;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			return 0;
		int a, b, w;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &w);
			adj[a].push_back({ b, w });
			adj[b].push_back({ a, w });
			tot += w;
		}
		DISJOINT ds;
		priority_queue<P, vector<P>, greater<P>> q;
		q.push({ 0, 1 });
		int ans = 0;
		int ansSize = 1;
		while (q.size()) {
			int c = q.top().first;
			int x = q.top().second;
			chk[x] = 1;
			q.pop();
			for (int i = 0; i < adj[x].size(); ++i) {
				if (!chk[adj[x][i].first])
					q.push({ adj[x][i].second, adj[x][i].first });
			}
			while (1) {
				P cur = q.top();
				if (ds.Find(x) != ds.Find(cur.second)) {
					ds.Union(x, cur.second);
					ans += cur.first;
					++ansSize;
					break;
				}
				q.pop();
			}
			if (ansSize == n)
				break;
		}

		printf("%d\n", tot - ans);
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		memset(chk, 0, sizeof(chk));
	}
}