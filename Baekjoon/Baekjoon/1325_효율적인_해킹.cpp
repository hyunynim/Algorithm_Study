#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

bool chk[12345];

vector<int> edge[10010];

int DFS(int v) {
	if (chk[v])
		return 0;
	chk[v] = 1;
	int ret = 1;
	for (int i = 0; i < edge[v].size(); ++i)
		ret += DFS(edge[v][i]);
	return ret;
}

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a;
		--b;
		edge[b].push_back(a);
	}

	int maxCnt = DFS(0), tmp;
	vector<int> ans;
	ans.push_back(0);
	for (int i = 1; i < n; ++i) {
		memset(chk, 0, sizeof(chk));
		tmp = DFS(i);
		if (tmp > maxCnt) {
			maxCnt = tmp;
			ans.clear();
			ans.push_back(i);
		}
		else if (tmp == maxCnt)
			ans.push_back(i);
	}
	for (int i : ans)
		printf("%d ", i + 1);
}