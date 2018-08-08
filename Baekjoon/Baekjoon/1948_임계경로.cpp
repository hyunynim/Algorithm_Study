#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<functional>
using namespace std;
typedef pair<int, int> P;
vector<P> adj[10001];
vector<int> p[10001];
int ind[10001];
int ans[10001];
int st, de;

int path(int s) {
	if (s == st)
		return 1;
	else {
		int tmp = 1;
		for (int i = 0; i < p[s].size(); ++i) {
			if (p[s][i]) {
				tmp += path(p[s][i]);
				p[s][i] = 0;
			}
		}
		return tmp;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
		ind[b]++;
	}
	scanf("%d %d", &st, &de);


	int curCnt = 0;
	queue<int> q;
	q.push(st);
	int tmp = 0;
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nx = adj[cur][i].first;
			int nc = adj[cur][i].second;
			ind[nx]--;
			if (ans[nx] < nc + ans[cur]) {
				ans[nx] = nc + ans[cur];
				p[nx].clear();
				p[nx].push_back(cur);
			}
			else if (ans[nx] == nc + ans[cur])
				p[nx].push_back(cur);
			if (ind[nx] == 0) {
				q.push(nx);
			}
		}
	}
	printf("%d\n", ans[de]);
	printf("%d", path(de) - 1);
}