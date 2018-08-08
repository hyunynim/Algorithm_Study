#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

#define VMAX 123
#define INF 1e9
int n, m, a, b;

int graph[VMAX][VMAX];

void floyd() {
	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
	for (int i = 0; i < VMAX; ++i) {
		for (int j = 0; j < VMAX; ++j) {
			graph[i][j] = INF;
			if (i == j)
				graph[i][j] = 0;
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a; --b;
		graph[a][b] = min(graph[a][b], 1);
		graph[b][a] = min(graph[b][a], 1);
	}
	floyd();
	vector<pair<long long, int>> ans;
	for (int i = 0; i < n; ++i) {
		long long sum = 0;
		for (int j = 0; j < n; ++j)
			sum += graph[i][j];
		ans.push_back({ sum, i });
	}
	sort(ans.begin(), ans.end());
	printf("%d", ans[0].second + 1);
}