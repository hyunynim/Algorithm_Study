#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return (b, a%b);
}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return (a / g) * (b / g) * g;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> note(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &note[i]);

	vector<int> r;
	for (int i = 0; i < n; ++i) {
		r.push_back(note[i] % k);
	}
	sort(r.begin(), r.end());
	r.erase(unique(r.begin(), r.end()), r.end());
	vector<int> ans;

	for (int i = 0; i < r.size(); ++i) {
		bool chk[100001] = { 0 };
		ll tmp = r[i] % k;
		while (!chk[tmp]) {
			chk[tmp] = 1;
			ans.push_back(tmp);
			tmp = (tmp + r[i]) % k;
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i]);
	}
}