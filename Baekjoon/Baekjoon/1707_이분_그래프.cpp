#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<string.h>
using namespace std;

int check[21234];
vector<int> edge[20004];
int v, e, from, to;

int DFS(int start, int color) {
	if (start >= v)
		return 0;
	
	int & ans = check[start];
	if (ans != 0) {
		if (ans == color)
			return 1;
		else
			return 0;
	}
	ans = color;
	int ret = 1;
	for (int i = 0; i < edge[start].size(); ++i)
		ret = min(ret, DFS(edge[start][i], 3 - color));
	return ret;
}

int main() {
	int t;
	
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		memset(check, 0, sizeof(check));
		int ans = 1;
		scanf("%d %d", &v, &e);
		for (int i = 0; i < v; ++i)
			edge[i].clear();

		for (int i = 0; i < e; ++i) {
			scanf("%d %d", &from, &to);
			--from;
			--to;
			edge[from].push_back(to);
			edge[to].push_back(from);
		}
		for (int i = 0; i < v; ++i)
		{
			if (check[i] == 0)
				ans = min(ans, DFS(i, 1));
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
}