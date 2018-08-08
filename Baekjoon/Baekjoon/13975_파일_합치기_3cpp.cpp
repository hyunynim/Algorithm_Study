#include<cstdio>
#include<functional>
#include<queue>
#include<algorithm>
typedef long long ll;
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		int n, tmp;
		scanf("%d", &n);
		priority_queue<ll, vector<ll>, greater<ll>> q;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			q.push(tmp);
		}
		ll sum = 0;
		while (q.size() > 1) {
			ll tmp = 0;

			tmp += q.top();
			q.pop();
			tmp += q.top();
			q.pop();
			sum += tmp;
			q.push(tmp);
		}
		printf("%lld\n", sum);
		while (q.size())
			q.pop();
	}
}