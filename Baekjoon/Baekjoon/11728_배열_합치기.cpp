#include<cstdio>
#include<queue>

using namespace std;

int main() {
	int n, m;
	queue<int> a, b;
	scanf("%d %d", &n, &m);
	int tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		a.push(tmp);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &tmp);
		b.push(tmp);
	}
	while (a.size() && b.size()) {
		if (a.front() < b.front()) {
			printf("%d ", a.front());
			a.pop();
		}
		else {
			printf("%d ", b.front());
			b.pop();
		}
	}
	while (a.size()) {
		printf("%d ", a.front());
		a.pop();
	}
	while (b.size()) {
		printf("%d ", b.front());
		b.pop();
	}
}