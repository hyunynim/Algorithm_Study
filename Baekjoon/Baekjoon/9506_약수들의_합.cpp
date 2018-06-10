#include<cstdio>
#include<vector>
#include<math.h>
typedef long long ll;
using namespace std;

void FindDiv(vector<ll> & div, ll n) {
	ll res = 0;
	for (ll i = 2; i <= (ll)sqrt(n); ++i) {
		if (n % i == 0) {
			div.push_back(i);
			res += i;
		}
	}
	for (ll i = div.size() - 1; i >= 0; --i) {
		if (i == div.size() - 1 && n / div[i] == div.back())
			continue;
		div.push_back(n / div[i]);
		res += n / div[i];
	}
	div.push_back(res);
}

int main() {
	ll n, res;
	vector<ll> vtmp;
	while (1) {
		scanf("%lld", &n);
		if (n == -1)
			return 0;
		vtmp.clear();
		FindDiv(vtmp, n);
		if (n == vtmp.back() + 1) {
			printf("%lld = 1 + ", n);
			for (int i = 0; i < vtmp.size() - 1; ++i) {
				printf("%lld%s", vtmp[i], i == vtmp.size() - 2 ? "" : " + ");
			}
			printf("\n");
		}
		else
			printf("%lld is NOT perfect.\n", n);
	}
}