#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n;
int g[100][100] = { 0 };

void FindPath(vector<int> & path, int v) {
	bool isChk[100] = { 0 };
	queue<int> searchPath;
	for (int i = 0; i < n; ++i) {
		if (g[v][i])
			searchPath.push(i);
	}
	while (searchPath.size()) {
		int cur = searchPath.front();
		isChk[cur] = 1;
		path.push_back(cur);
		searchPath.pop();
		for (int i = 0; i < n; ++i) {
			if (g[cur][i] && isChk[i] != 1)
				searchPath.push(i);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &g[i][j]);
		}
	}
	vector<int> * path = new vector<int>[n];

	for (int i = 0; i < n; ++i) {
		FindPath(path[i], i);
		for (int j = 0; j < path[i].size(); ++j) {
			for (int k = 0; k < n; ++k) {
				g[i][k] |= g[path[i][j]][k];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}