#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
#define MAX_V 100001
#define INF (int)1e8

int v, e;
vector<pair<int, int> > edge[MAX_V];

void dijkstra(int start, vector<int> & ans) {
	ans.resize(v);
	fill(ans.begin(), ans.end(), INF);
	ans[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));

	while (pq.size()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (ans[cur] < cost) continue;

		for (int i = 0; i < edge[cur].size(); ++i) {
			int toGo = edge[cur][i].first;
			int nextDist = cost + edge[cur][i].second;

			if (ans[toGo] > nextDist) {
				ans[toGo] = nextDist;
				pq.push(make_pair(-nextDist, toGo));
			}
		}
	}
}
int main() {
	int k;
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &v, &k, &e);
	for (int i = 0; i < e; ++i) {
		int a, b;
		scanf("%d", &a);
		--a;
		for (int j = 0; j < k - 1; ++j) {
			scanf("%d", &b);
			--b;
			edge[a].push_back({ b, 1 });
			edge[b].push_back({ a, 1 });
		}
	}
	vector<int> tmp;
	dijkstra(0, tmp);
	int ans = tmp[v - 1] + 1;
	printf("%d", ans > 1000000 ? -1 : ans);
}

/*comment*/
//하나의 하이퍼튜브에 있는 역들은 모두 연결되어 있음을 빼먹음
//K개의 정점으로 이루어진 M개의 완전그래프를 어떤식으로 입력받아야 하나