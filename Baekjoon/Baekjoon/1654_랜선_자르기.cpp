#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

vector<ll> seq;
ll n, x;

bool chk(ll len) {
	ll sum = 0;
	for (int i = 0; i < n; ++i)
		sum += seq[i] / len;
	return sum >= x;
}

int main() {
	scanf("%lld %lld", &n, &x);
	seq.resize(n);
	ll l = 1, r = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &seq[i]);
		r = max(r, seq[i]);
	}
	ll ans = 0;
	while (l <= r) {
		ll len = (l + r) / 2;
		if (chk(len)) {
			ans = max(ans, len);
			l = len + 1;
		}
		else {
			r = len - 1;
		}
	}
	printf("%lld", ans);
}