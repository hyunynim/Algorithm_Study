#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define VMAX 521
#define INF 1e9
int n, m, a, b, w;

int graph[VMAX][VMAX];
int path[VMAX][VMAX];

vector<int> bark;
vector<int> vTmp[2];
int getMax(vector<int> & vPath, int len) {
	int ans = 0;
	for (int i = 0; i < vPath.size(); ++i)
		ans = max(ans, bark[vPath[i]]);
	return ans + len;
}

int getPath(int s, int e, vector<int> & pathTmp) {
	int ans = 0;
	if (path[s][e] != -1) {
		ans += getPath(s, path[s][e], pathTmp);
		ans += getPath(path[s][e], e, pathTmp);
	}
	else {
		pathTmp.push_back(e);
		ans = graph[s][e];
	}
	return ans;
}

void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vTmp[0].clear(); vTmp[1].clear();
				vTmp[0].push_back(i);
				vTmp[1].push_back(i);
				int len1 = getPath(i, j, vTmp[0]);
				int len2 = getPath(i, k, vTmp[1]);
				len2 += getPath(k, j, vTmp[1]);
				len1 = getMax(vTmp[0], len1);
				len2 = getMax(vTmp[0], len2);
				if (len1 > len2) {
					graph[i][j] = len2;
					path[i][j] = k;
				}
				else
					graph[i][j] = len1;
				//path 없음
				//graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

				//path추적
				//if (graph[i][j] > graph[i][k] + graph[k][j]) {
				//	graph[i][j] = graph[i][k] + graph[k][j];
				//	path[i][j] = k;
				//}
			}
		}
	}
}

int main() {
	int q;
	scanf("%d %d %d", &n, &m, &q);
	bark.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &bark[i]);
		for (int j = 0; j < n; ++j) {
			graph[i][j] = INF;
			if (i == j)
				graph[i][j] = 0;
			path[i][j] = -1;
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		--a; --b;
		graph[a][b] = min(graph[a][b], w);
		graph[b][a] = min(graph[b][a], w);
	}
	floyd();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] >= INF)
				graph[i][j] = 0;
			printf("%d ", graph[i][j]);
		}
		puts("");
	}
	/*
	for (int i = 0; i < q; ++i) {
	scanf("%d %d", &a, &b);
	--a; --b;
	printf("%d\n", getPath(a, b));
	}
	*/

}