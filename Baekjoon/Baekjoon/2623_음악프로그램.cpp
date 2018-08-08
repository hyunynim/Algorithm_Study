#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

vector<int> adj[1234];
int ind[1234];

int main() {
	int n, m;
	int num[1234];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d", &a);
		for (int j = 0; j < a; ++j) 
			scanf("%d", &num[j]);
		for (int j = 1; j < a; ++j) {
			adj[num[j - 1]].push_back(num[j]);
			ind[num[j]]++;
		}
	}
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; ++i) {
		if (ind[i] == 0)
			q.push(i);
	}
	vector<int> ans;
	while (q.size()) {
		int cur = q.top(); q.pop();
		ans.push_back(cur);
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nx = adj[cur][i];
			ind[nx]--;
			if (ind[nx] == 0)
				q.push(nx);
		}
	}
	if (ans.size() != n)
		printf("0");
	else {
		for (int i : ans)
			printf("%d\n", i);
	}
}