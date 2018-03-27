#include <iostream>
#include <queue>
#include <stack>

using namespace std;
bool isChecked1[1001] = { 0 };
bool isChecked2[1001] = { 0 };

void BFS(int ** line, int start, int n)
{
	queue <int> q;
	q.push(start);
	int cur = start;
	while (1) {
		printf("%d ", q.front());
		for (int i = 0; i < n; i++) {
			if (line[cur][i] == -1)
				break;
			if (isChecked1[line[cur][i]] == 1)
				continue;
			q.push(line[cur][i]);
			isChecked1[line[cur][i]] = 1;
		}
		q.pop();
		if (q.size() == 0)
			break;
		cur = q.front();
	}
}
void DFS(int ** line, int start, int n) {
	stack <int> s, tmp;
	s.push(start);
	int cur = start;
	while (1) {
		if (isChecked2[s.top()] == 0) {
			printf("%d ", s.top());
			isChecked2[s.top()] = 1;
		}
		s.pop();
		for (int i = 0; i < n; i++) {
			if (line[cur][i] == -1)
				break;
			tmp.push(line[cur][i]);
		}
		while (tmp.size() != 0) {
			s.push(tmp.top());
			tmp.pop();
		}
		if (s.size() == 0)
			break;
		cur = s.top();
	}
}

int main() {
	int n, m, v;
	int start, finish;

	scanf("%d %d %d", &n, &m, &v);

	int ** line = new int *[n + 1];
	int * linecnt = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		linecnt[i] = 0;
		line[i] = new int[n];
		for (int j = 0; j < n; j++)
			line[i][j] = -1;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &start, &finish);
		line[start][linecnt[start]] = finish;
		linecnt[start]++;
	}

	DFS(line, v, n);
	printf("\n");
	BFS(line, v, n);
}

/*comment*/
//메모리초과 line변수 때문인듯
//short로 해봤는데 안됨