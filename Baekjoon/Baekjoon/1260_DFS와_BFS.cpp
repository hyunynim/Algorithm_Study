#include <iostream>
#include <queue>
#include <stack>

using namespace std;
bool isChecked1[1001] = { 0 };
bool isChecked2[1001] = { 0 };
bool graph[1001][1001] = { 0 };

void BFS(int start, int n)
{
	queue <int> q;
	q.push(start);
	int cur;
	while (1) {
		if (q.size() != 0) {
			cur = q.front();
			if (isChecked1[cur]);
			else
				printf("%d ", cur);
			isChecked1[cur] = 1;
			q.pop();
		}

		for (int i = 1; i <= n; ++i) {
			if (graph[cur][i] && isChecked1[i] == 0)
				q.push(i);
		}
		if (q.size() == 0)
			break;
	}
	
}
void DFS(int start, int n) {
	stack <int> s, tmp;
	s.push(start);
	int cur;
	while (1) {
		if (s.size()) {
			cur = s.top();
			if (isChecked2[cur]);
			else
				printf("%d ", cur);
			isChecked2[cur] = 1;
			s.pop();
		}

		for (int i = 1; i <= n; ++i) {
			if (graph[cur][i] && isChecked2[i] == 0)
				tmp.push(i);
		}
		while (tmp.size()) {
			s.push(tmp.top());
			tmp.pop();
		}
		if (s.size() == 0)
			break;
	}
}

int main() {
	int n, m, v;
	int start, finish;

	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &start, &finish);
		graph[start][finish] = 1;
		graph[finish][start] = 1;
	}

	DFS(v, n);
	printf("\n");
	BFS(v, n);

}

/*comment*/
//메모리초과 line변수 때문인듯
//short로 해봤는데 안됨
//Bool로 관계행렬 짜서 만들어봤지만
//틀림
//이래저래 돌려봤는데 잘 안됨..하
//관계행렬 이용
//드디어 맞았다!!!!!!!!!!!!