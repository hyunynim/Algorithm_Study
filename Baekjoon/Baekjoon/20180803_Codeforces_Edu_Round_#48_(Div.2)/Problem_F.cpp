#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<utility>
#include<functional>
#include<string.h>
#include<string>

typedef long long ll;
using namespace std;

ll minLen;
vector<pair<int, int>> adj[300002];
vector<int> x;
int n, m;
bool chk[300001];
void DFS(int s) {
	chk[s] = 1;
	if (s == n) {
		
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int a, b, w;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back({ b, w });
		adj[b].push_back({ a,w });
	}
	x.resize(m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &x[i]);
}