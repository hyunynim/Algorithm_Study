#include<cstdio>
#include<queue>

using namespace std;

bool isChecked[1001] = { 0 };
bool graph[1001][1001] = { 0 };
int res = 0;

void BFS(int start, int n)
{
	queue <int> q;
	q.push(start);
	int cur;
	while (1) {
		if (q.size() != 0) {
			cur = q.front();
			if (isChecked[cur]) {
				q.pop();
				continue;
			}
			isChecked[cur] = 1;
			q.pop();
		}

		for (int i = 1; i <= n; ++i) {
			if (graph[cur][i] && isChecked[i] == 0)
				q.push(i);
		}
		if (q.size() == 0)
			break;
	}
	res++;
}


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (!isChecked[i])
			BFS(i, n);
	}
	printf("%d", res);
}