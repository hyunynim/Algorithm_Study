#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define VMAX 66
#define INF 1e9
int n = VMAX, m, a, b, w;

int graph[VMAX][VMAX];

void floyd() {
	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
	char msg[3][10];
	vector<char> vtmp[2];
	scanf("%d", &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			graph[i][j] = INF;
			if (i == j)
				graph[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%s %s %s", msg[0], msg[1], msg[2]);
		graph[msg[0][0] - 'A'][msg[2][0] - 'A'] = min(graph[msg[0][0] - 'A'][msg[2][0] - 'A'], 1);
	}
	floyd();
	vector<pair<int, int>> ans;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(graph[i][j] >= INF) graph[i][j] = 0;
			if (graph[i][j]) {
				++cnt;
				ans.push_back({ i, j });
			}
		}
	}
	printf("%d\n", cnt);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%c => %c\n", ans[i].first + 'A', ans[i].second + 'A');
	}
}