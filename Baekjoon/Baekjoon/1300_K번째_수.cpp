#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, k;

P chk(ll num) {
	ll sum = 0, cnt = 0;
	for (ll i = 1; i <= n; ++i) {
		sum += min(num / i, n);
		cnt += (num%i == 0 && n*i >= num) ? 1 : 0;
	}
	return { sum - cnt, sum };
}
int main() {
	scanf("%lld %lld", &n, &k);
	ll l = 1;
	ll r = n*n;
	ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		auto p = chk(mid);
		if (p.first < k && k <= p.second) {
			ans = mid;
			r = mid - 1;
		}
		else if (p.second < k)
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%lld", ans);
}