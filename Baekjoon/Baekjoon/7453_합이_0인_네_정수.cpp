#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	vector<int> a, b, c, d;
	int n;
	scanf("%d", &n);
	a.resize(n);
	b.resize(n);
	c.resize(n);
	d.resize(n);
	for (int i = 0; i < n; ++i) 
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	
	vector<int> sum[2];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum[0].push_back(-(a[i] + b[j]));
			sum[1].push_back(c[i] + d[j]);
		}
	}
	a.clear();
	b.clear();
	c.clear();
	d.clear();
	sort(sum[0].begin(), sum[0].end());
	sort(sum[1].begin(), sum[1].end());
	ll ans = 0;
	while (sum[1].size() && sum[0].size()) {
		int curA = -sum[0].back();
		int curB = sum[1].back();
		int res = curA + curB;
		if (res > 0 && sum[1].size())
			sum[1].pop_back();
		else if (res < 0 && sum[0].size())
			sum[0].pop_back();
		if (res == 0) {
			sum[1].pop_back();
			sum[0].pop_back();
			ll A = 1;
			while (sum[0].size() && sum[0].back() == -curA) {
				++A; sum[0].pop_back();
			}
			ll B = 1;
			while (sum[1].size() && sum[1].back() == curB) {
				++B; sum[1].pop_back();
			}
			ans += A * B;
		}
	}
	printf("%lld", ans);
}