#include<cstdio>
#include<queue>
#include<functional>
using namespace std;

vector<int> adj[32100];
int ind[32100];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		ind[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; ++i) {
		if (ind[i] == 0)
			q.push(i);
	}
	while (q.size()) {
		int cur = q.top();
		printf("%d ", cur);
		q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nx = adj[cur][i];
			ind[nx]--;
			if (ind[nx] == 0)
				q.push(nx);
		}
	}
}