#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
#define MAX_V 20001
#define INF (int)1e9

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
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;
		edge[a].push_back({ b, 1 });
		edge[b].push_back({ a, 1 });
	}
	vector<int> tmp;
	vector<pair<int, int>> ans;
	dijkstra(0, tmp);
	for (int i = 0; i < tmp.size(); ++i) 
		ans.push_back({ tmp[i], i + 1 });

	sort(ans.begin(), ans.end());
	int cnt = 0;
	for (int i = ans.size() - 1; i >= 0; --i) {
		if (ans[i].first != ans[i - 1].first)
			break;
		++cnt;
	}
	printf("%d %d %d", ans[ans.size() - cnt - 1].second, ans[ans.size() - cnt - 1].first, cnt + 1);
}