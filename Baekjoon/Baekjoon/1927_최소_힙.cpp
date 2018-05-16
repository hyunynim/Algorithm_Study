#include<cstdio>
#include<queue>
#include <functional> 
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int> > q;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int com;
		scanf("%d", &com);
		if (com == 0) {
			if (q.size()) {
				printf("%d\n", q.top());
				q.pop();
			}
			else
				printf("0\n");
		}
		else
			q.push(com);
	}
}