#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

#define VMAX 55
#define INF 1e9
int n, m, a, b, w;

int graph[VMAX][VMAX];


void floyd() {
	for (int k = 0; k<VMAX; k++)
		for (int i = 0; i<VMAX; i++)
			for (int j = 0; j<VMAX; j++)
				graph[i][j] = max(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
	vector<char> vtmp;
	char msg[123][12];
	scanf("%d", &n);
	for (int i = 0; i < VMAX; ++i) {
		for (int j = 0; j < VMAX; ++j) {
		graph[i][j] = -INF;
		if (i == j)
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg[i]);
		for (int j = 0; j < msg[i][j] != '\0'; ++j)
			vtmp.push_back(msg[i][j]);
	}
	sort(vtmp.begin(), vtmp.end());
	vtmp.erase(unique(vtmp.begin(), vtmp.end()), vtmp.end());
	int alphaCnt = vtmp.size();
	for (int i = 0; i < n - 1; ++i) {
		bool same = 1;
		for (int j = 0; j < msg[i][j] != '\0' && msg[i+1][j] != '\0'; ++j) {
			if (msg[i][j] != msg[i + 1][j] && same) {
				int start = msg[i][j] - 'a';
				int end = msg[i + 1][j] - 'a';
				graph[start][end] = max(graph[start][end], 1);
				same = 0;
			}
			else if (msg[i][j] == msg[i + 1][j])
				same = 1;			
		}
	}

	floyd();
	int maxCnt = 0;
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (graph[i][j] < 0)
				graph[i][j] = 0;
			printf("%d ", graph[i][j]);
			maxCnt = max(maxCnt, graph[i][j]);
		}
		puts("");
	}
	printf("a: %d m: %d", alphaCnt, maxCnt);
}