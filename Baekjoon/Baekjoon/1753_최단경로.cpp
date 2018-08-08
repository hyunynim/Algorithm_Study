#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
#define INF 987654321

vector <pair<int, int>> edges[20001];
bool isChecked[20001] = { 0 };

int main() {
	int v, e, k, numRes;

	scanf("%d %d", &v, &e);
	vector <int> res(v + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> search;

	for (int i = 0; i < e; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back(make_pair(w, v));
	}
	scanf("%d %d", &k, &numRes);
	res[k] = 0;
	isChecked[k] = 1;
	int cur = -1, curDist = 0;
	search.push(make_pair(0, k));
	while (search.size()) {
		cur = search.top().second;
		if (cur != k && isChecked[cur]) {
			search.pop();
			continue;
		}
		curDist = search.top().first;
		search.pop();
		
		for (int i = 0; i < edges[cur].size(); ++i) {
			if (curDist + edges[cur][i].first < res[edges[cur][i].second]) {
				res[edges[cur][i].second] = curDist + edges[cur][i].first;
				search.push(make_pair(curDist + edges[cur][i].first, edges[cur][i].second));
			}
		}
	}/*
	for (int i = 1; i < res.size(); ++i) {
		if (res[i] > 10000000)
			printf("INF\n");
		else
			printf("%d\n", res[i]);
	}
	*/
	printf("%d", res[numRes]);
}

/*comment*/
//걍 갈아엎음
//Recursive 하게 짜봄
//메모리 초과
//다시 처음부터
//우선순위 큐 이용했는데 메모리초과
//어떻게 해야 메모리초과를 해결할 수 있을까
//min함수대신 기존 거리와 비교해서 짧을때만 queue에 넣도록 변경
//런타임에러
//res초기화 시 간선개수가 아닌 정점 개수로 초기화
//res 한부분 잘못쓰여있었음
//맞음