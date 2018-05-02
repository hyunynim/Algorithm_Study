#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define INT_MAX 2100000000

vector<int> edge[20001];
vector<int> picked;
int res[20001];
bool isCheck[20001]; 
int curEdge, curDist, cur, curPath = 0;


int CompEdgeDist(int dist, int edge) {
	return dist * 100000 + edge;
}

void DecompEdgeDist(int comp, int * dist, int * edge) {
	*dist = comp / 100000;
	*edge = comp % 100000;
}
void printPath(vector<int> & path) {
	for (int i = 0; i < path.size(); ++i)
		printf("%d ", path[i]);
	printf("\n");
}

void Dijk(vector<int> & picked, int curPath) {
	int cur = picked.back();
//	printPath(picked);
		if (res[cur] == -1)
			res[cur] = curPath;
		else
			res[cur] = min(res[cur], curPath);
		int dist, vert;
		vector<pair<int, int>> next;
		for (int i = 0; i < edge[cur].size(); ++i) {
			DecompEdgeDist(edge[cur][i], &dist, &vert);
			next.push_back(make_pair(dist, vert));
		}
		sort(next.begin(), next.end());
		for (int i = 0; i < edge[cur].size(); ++i) {
			picked.push_back(next[i].second);
			Dijk(picked, curPath + next[i].first);
			picked.pop_back();
		}
	
}

int main() {
	int v, e, k;
	scanf("%d %d %d", &v, &e, &k);
	for (int i = 0; i < e; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[u].push_back(CompEdgeDist(w, v));
	}
	picked.push_back(k);
	for (int i = 0; i < v + 1; ++i) {
		res[i] = -1;
		isCheck[i] = 0;
	}
	res[k] = 0;
	isCheck[k] = 1;
	vector<int> path;
	path.push_back(k);
	Dijk(path, 0);
	for (int i = 1; i < v + 1; ++i) {
		if (res[i] == -1)
			printf("INF\n");
		else
			printf("%d\n", res[i]);
	}
}

/*comment*/
//°Á °¥¾Æ¾þÀ½
//Recursive ÇÏ°Ô Â¥º½
//¸Þ¸ð¸® ÃÊ°ú