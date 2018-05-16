#include<queue>
#include<cstdio>
#include<functional>
using namespace std;

int ABS(int a) {
	return a > 0 ? a : -a;
}

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			if (q.size()) {
				printf("%d\n", q.top().second);
				q.pop();
			}
			else
				printf("0\n");
		}
		else
			q.push(make_pair(ABS(a), a));
	}

}