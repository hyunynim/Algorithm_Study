#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
typedef pair<int, int> P;
#define VMAX 123
#define INF 1e9
int t, n, x, y;
vector<P> drug;

int graph[VMAX][VMAX];
int path[VMAX][VMAX];
int chk[VMAX];
int ABS(int a) { return a > 0 ? a : -a; }
int dis(P a, P b) {
	return ABS(a.first - b.first) + ABS(a.second - b.second);
}
void floyd() {
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

bool DFS(int v) {
	if (v == n + 1) {
		printf("happy\n");
		return 1;
	}
	if (chk[v] == 1)
		return 0;
	else {
		chk[v] = 1;
		for (int i = 0; i < n + 2; ++i) {
			if (v == i)
				continue;
			if (graph[v][i] <= 1000 && DFS(i))
				return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		memset(chk, -1, sizeof(chk));
		drug.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				graph[i][j] = INF;
				path[i][j] = -1;
				if (i == j)
					graph[i][j] = 0;
			}
		}
		scanf("%d %d", &x, &y);
		drug.push_back({ x, y });
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			drug.push_back({ x, y });
		}
		scanf("%d %d", &x, &y);
		drug.push_back({ x, y });
		for (int i = 0; i < n + 2; ++i) {
			for (int j = 0; j < n + 2; ++j) {
				graph[i][j] = graph[j][i] = dis(drug[i], drug[j]);
			}
		}
		floyd();

		if (!DFS(0))
			printf("sad\n");
	}
}

/*comment*/
//플로이드 알고리즘도 안썼고 아예 틀리게 풀었음
//완전히 DFS탐색을 하게끔 함