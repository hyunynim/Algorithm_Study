#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;

vector<int> adj[200001];
vector<int> dfs;
bool chk[200001];
int cnt[200001];
int ind[200001];
int DFS(int s) {
	if (chk[s])
		return 0;

	chk[s] = 1;
	dfs.push_back(s);
	ind[s] = dfs.size() - 1;
	cnt[s] = adj[s].size();
	for (int i = 0; i < adj[s].size(); ++i) {
		cnt[s] += DFS(adj[s][i]);
	}
	return cnt[s];
}
int main() {
	int n, q, tmp;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d", &tmp);
		adj[tmp - 1].push_back(i + 1);
	}
	DFS(0);
	int a, b;
	for (int i = 0; i < q; ++i) {
		scanf("%d %d", &a, &b);
		if (cnt[a - 1] < b - 1)
			puts("-1");
		else {
			printf("%d\n", dfs[ind[a-1] + b - 1] + 1);
		}
	}
}