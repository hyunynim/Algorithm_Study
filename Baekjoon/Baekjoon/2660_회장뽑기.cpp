#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define VMAX 521
#define INF 1e9
int n, m, a, b, w;

int graph[VMAX][VMAX];

void floyd() {
	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			graph[i][j] = INF;
			if (i == j)
				graph[i][j] = 0;
		}
	}
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1)
			break;
		--a; --b;
		graph[a][b] = min(graph[a][b], 1);
		graph[b][a] = min(graph[b][a], 1);
	}
	floyd();
	vector<pair<int, int>> ans(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] >= INF)
				graph[i][j] = 0;
			ans[i].first = max(ans[i].first, graph[i][j]);
		}
		ans[i].second = i;
	}

	sort(ans.begin(), ans.end());
	int minPath = ans[0].first;
	int minCnt = 0;
	for (auto & p : ans) {
		if (p.first == minPath)
			++minCnt;
		else
			break;
	}
	printf("%d %d\n", minPath, minCnt);
	for (auto & p : ans) {
		if (p.first == minPath)
			printf("%d ", p.second + 1);
		else
			break;
	}
}