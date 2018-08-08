#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

vector<int> adj[123456];

bool chk[123456];

bool DFS(int first, int s, vector<int> & pick) {
	chk[s] = 1;
	for (int i = 0; i < adj[s].size(); ++i) {
		if (chk[adj[s][i]] && adj[s][i] == first)
			return 1;
		if (!chk[adj[s][i]] && DFS(first, adj[s][i], pick)) {
			pick.push_back(adj[s][i]);
			return 1;
		}
		else
			chk[adj[s][i]] = 0;
	}
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		memset(chk, 0, sizeof(chk));
		int num;
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &num);
			adj[i].push_back(num - 1);
		}
		
		for (int i = 0; i < n; ++i) {
			if (!chk[i] && DFS(i, i, ans))
				ans.push_back(i);
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		printf("%d\n", n - ans.size());
		ans.clear();
	}
}