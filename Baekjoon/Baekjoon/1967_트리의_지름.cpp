#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int, int>> edge[10001];
vector<int> path[10001];
bool chk[12345];

int DFS(int v, int w) {
	if (chk[v] || edge[v].size() == 0)
		return 0;
	chk[v] = 1;
	int ans = 0, tmp;
	for (int i = 0; i < edge[v].size(); ++i) {
		tmp = DFS(edge[v][i].first, w) + edge[v][i].second;
		path[v].push_back(tmp);
		ans = max(ans, tmp);
	}
	return ans;
}

int main() {
	int n, a, b, w;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		edge[a].push_back({ b, w });
	}
	for (int i = 0; i < edge[1].size(); ++i) {
		DFS(1, edge[1][i].first);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (path[i].size() == 1)
			ans = max(ans, path[i][0]);
		if (path[i].size() > 1) {
			for (int j = 0; j < path[i].size() - 1; ++j) {
				ans = max(ans, path[i][j] + path[i][j + 1]);
			}
		}
	}
	printf("%d", ans);		
}

/*comment*/
//완전 한쪽으로만 기울어져있는 트리의 경우 고려를 안함