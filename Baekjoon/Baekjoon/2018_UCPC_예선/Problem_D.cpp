#include<cstdio>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<utility>
#include<functional>
#include<cmath>

using namespace std;
int leaf = 0;
vector<pair<int,int>> leafList;
vector<int> edge[500001];
int n;
bool chk[500001];
void DFS(int start, int len) {
	int nodeCnt = 0;
	chk[start] = 1;
	for (int i = 0; i < edge[start].size(); ++i) {
		int next = edge[start][i];
		if (!chk[next]) {
			DFS(next, len+1); nodeCnt++;
		}
	}
	if (nodeCnt == 0) {
		leaf++; leafList.push_back({ start, len });
	}
}

int main() {
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d", &a, &b);
		--a; --b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	DFS(0, 0);
	long long ans = 0;
	for (int i = 0; i < leafList.size(); ++i) {
		ans += leafList[i].second;
	}
	printf("%s", ans % 2 ? "Yes" : "No");
}