#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	if (m + k - 1 <= n && n <= m * k) {
		vector<int> ans;
		queue<int> q;
		stack<int> s;
		for (int i = 0; i < n; ++i)
			q.push(i + 1);
		int next = k;
		int cnt = 0;
		while (q.size()) {
			for (int i = 0; i < next; ++i) {
				if (q.empty())
					break;
				s.push(q.front());
				q.pop();
			}
			while (s.size()) {
				ans.push_back(s.top());
				s.pop();
			}
			--m;
			next = m == 0 ? 1 : q.size() / m;
		}
		for (int i : ans)
			printf("%d ", i);
	}
	else {
		printf("-1");
	}
}