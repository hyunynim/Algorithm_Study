#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> adj[543];
int ind[543];
int t[543];
int ans[543];
int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		while(1){
			scanf("%d", &a);
			if (a == -1)
				break;
			if(cnt){
				adj[a - 1].push_back(i);
				ind[i]++;
			}
			else {
				t[i] = a;
				ans[i] = t[i];
			}
			++cnt;
		}
	}

	int curCnt = 0;
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	int tmp = 0;
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nx = adj[cur][i];
			ind[nx]--;
				ans[nx] = max(ans[nx], t[nx] + ans[cur]);
			if (ind[nx] == 0) {
				q.push(nx);
			}
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", ans[i]);
}