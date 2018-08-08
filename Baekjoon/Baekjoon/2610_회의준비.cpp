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
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			graph[i][j] = INF;
			if (i == j)
				graph[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a; --b;
		graph[a][b] = min(graph[a][b], 1);
		graph[b][a] = min(graph[b][a], 1);
	}
	floyd();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (graph[i][j] >= INF)
				graph[i][j] = 0;
	vector<int> maxDis(n);
	for (int i = 0; i < n; ++i) {
		auto p = minmax_element(graph[i], graph[i] + n);
		maxDis[i] = *p.second;
	}
	bool chk[123] = { 0 };
	vector<int> ansList;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (!chk[i]) {
			chk[i] = 1;
			ansList.clear();
			ansList.push_back(i);
			for (int j = 0; j < n; ++j) {
				if (graph[i][j]) {
					ansList.push_back(j);
					chk[j] = 1;
				}
			}
			int minD = INF;
			int minI = 0;
			for (int j = 0; j < ansList.size(); ++j) {
				if (minD > maxDis[ansList[j]]) {
					minD = maxDis[ansList[j]];
					minI = ansList[j];
				}
			}
			ans.push_back(minI);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i : ans)
		printf("%d\n", i + 1);
}