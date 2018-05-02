#include <stdio.h>
#include <queue>

using namespace std;

bool net[101][101] = { 0 };
bool isChecked[101] = { 0, 1 };
int main() {
	int n, m;
	queue <int> search;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		net[a][b] = 1;
		net[b][a] = 1;
	}
	search.push(1);
	int res = 0;
	while (search.size()) {
		int cur = search.front();
		for (int i = 1; i <= 100; ++i) {
			if (net[cur][i] && isChecked[i] == 0)
				search.push(i);
		}
		if (isChecked[cur]);
		else {
			isChecked[cur] = 1;
			res++;
		}
		search.pop();
	}
	printf("%d", res);
}