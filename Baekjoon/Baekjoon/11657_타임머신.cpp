#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define INF 1e9
using namespace std;
typedef pair<int, int> P;
vector<P> edge[500];

int n, m, graph[512];
bool canGo = 1;
void BellmanFord() {
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) {
			for (int k = 0; k < edge[j].size(); ++k) {
				if (graph[j] != INF && graph[edge[j][k].first] > graph[j] + edge[j][k].second) {
					graph[edge[j][k].first] = graph[j] + edge[j][k].second;
					if (i == n - 1) canGo = 0;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; ++i) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		edge[A - 1].push_back(P(B - 1, C));
	}
	fill(graph, graph + n, INF);
	graph[0] = 0;
	BellmanFord();
	if (!canGo) { printf("-1\n"); }
	else {
		for (int i = 1; i < n; ++i)
			printf("%d\n", graph[i] != INF ? graph[i] : -1);
	}
}
