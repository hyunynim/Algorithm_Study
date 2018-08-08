#include<cstdio>
#include<algorithm>

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
		scanf("%d %d %d", &a, &b, &w);
		--a; --b;
		graph[a][b] = min(graph[a][b], w);
	}
	floyd();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] == 0)
				graph[i][j] = INF;
		}
	}
	int minCycle = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			minCycle = min(minCycle, graph[i][j] + graph[j][i]);
		}
	}
	printf("%d", minCycle >= INF ? -1 : minCycle);
}
/*comment*/
//없는 경우 처리 안함