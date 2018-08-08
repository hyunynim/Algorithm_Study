#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
vector<ll> sum;

int cnt[1234];
int main() {
	freopen("input.txt", "r", stdin);
	ll n, m, a;
	ll ans = 0;
	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < n; ++i) {
		scanf("%lld", &a);
		sum.push_back(sum.empty() ? a % m : (sum.back() + a) % m);
		cnt[sum.back()]++;
	}
	for (int i = 0; i < m; ++i) {
		ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
	}
	ans += cnt[0];

	printf("%lld", ans);
}