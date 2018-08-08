#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<string.h>
#define INF 1e9
using namespace std;
typedef pair<int, int> P;
vector<P> edge[500];

int n, m, w, graph[512];
bool canGo = 1;
bool chk[501];
void BellmanFord(int s) {
	for (int i = s; i<n; ++i) {
		for (int j = s; j<n; ++j) {
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
	int t;
	int a, b, time;
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		scanf("%d %d %d", &n, &m, &w);
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &time);
			--a; --b;
			edge[a].push_back({ b, time });
		}
		for (int i = 0; i < w; ++i) {
			scanf("%d %d %d", &a, &b, &time);
			--a; --b;
			edge[a].push_back({ b, -time });
		}
		fill(graph, graph + n, INF);
		for (int i = 0; i < n; ++i) {
			if (graph[i] == INF) {
				graph[i] = 0;
				BellmanFord(i);
			}
		}
		if (!canGo)  printf("YES\n"); 
		else printf("NO\n");
		for (int i = 0; i < n; ++i)
			edge[i].clear();
	}
}

/*comment*/
//여러 개의 component에 대해 고려 안해줌
//항상 모든 간선에 대해 check하므로 의도치 않은 결과 출력
//모르게따 어렵따.........