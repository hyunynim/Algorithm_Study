#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 2010
#define ll long long
ll cashe[MAXN][MAXN];
ll binomial(ll n, ll k, ll p) {
	if (cashe[n][k] != -1) return cashe[n][k];
	if (k == 0 || k == n)
		return cashe[n][k] = 1;
	return cashe[n][k] = (binomial(n - 1, k - 1, p) + binomial(n - 1, k, p) % p);
}
vector<ll> get_digits(ll n, ll b) {
	vector<ll> d;
	while (n) {
		d.push_back(n%b);
		n /= b;
	}
	return d;
}
ll lucas_theorem(ll n, ll k, ll p) {
	ll ret = 1;
	vector<ll> nd = get_digits(n, p), kd = get_digits(k, p);
	for (int i = 0; i < max(nd.size(), kd.size()); i++) {
		ll nn, kk;
		if (i < nd.size())
			nn = nd[i];
		else
			nn = 0;
		if (i < kd.size())
			kk = kd[i];
		else
			kk = 0;

		if (nn < kk)
			return 0;
		ret = (ret * binomial(nn, kk, p) % p);
	}
	return ret;
}
int main() {
	memset(cashe, -1, sizeof(cashe));
	ll N, K, M;
	cin >> N >> K >> M;
	cout << lucas_theorem(N, K, M) << endl;
	return 0;
}

/*comment*/
//루카스 정리