#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define VMAX 123
#define INF 1e9
int n, m, a, b, w;

int graph[VMAX][VMAX];
vector<int> bro[VMAX];

void floyd() {
	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
	int qa, qb;
	scanf("%d %d %d %d", &n, &qa, &qb, &m);
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
	printf("%d", graph[qa - 1][qb - 1] < INF ? graph[qa - 1][qb - 1] : -1);
}