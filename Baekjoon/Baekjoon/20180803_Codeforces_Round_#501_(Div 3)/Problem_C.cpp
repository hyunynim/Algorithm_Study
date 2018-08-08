#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;
vector<pair<ll, ll>> a;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	ll sum = 0, sum2 = 0;
	for (int i = 0; i < n; ++i) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		a.push_back({ x - y, y });
		sum += y;
		sum2 += x;
	}
	if (sum > m)
		printf("-1");
	else if (sum == m)
		printf("%d", n);
	else {
		sort(a.begin(), a.end(), greater<pair<ll, ll>>());
		int ans = 0;
		while (sum2 > m) {
			sum2 = sum2 - a[ans].first;
			++ans;
		}
		printf("%d", ans);
	}
}