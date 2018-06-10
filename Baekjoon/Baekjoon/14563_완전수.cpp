#include<cstdio>
#include<vector>
#include<math.h>
typedef long long ll;
using namespace std;

void FindDiv(vector<ll> & div, ll n) {
	for (ll i = 2; i <= (ll)sqrt(n); ++i) {
		if (n % i == 0)
			div.push_back(i);
	}
	if (div.size() == 0)
		return;
	for (ll i = div.size() - 1; i >= 0; --i) {
		if (i == div.size() - 1 && n / div[i] == div.back())
			continue;
		div.push_back(n / div[i]);
	}
}

int main() {
	ll n, t;
	scanf("%lld", &t);
	for (int tt = 0; tt < t; ++tt) {
		scanf("%lld", &n);
		ll sum = 1;
		vector<ll> vtmp;
		FindDiv(vtmp, n);
		if (vtmp.size() == 0) {
			printf("Deficient\n");
			continue;
		}
		for (int i = 0; i < vtmp.size(); ++i) 
			sum += vtmp[i];
		if (sum == n)
			printf("Perfect\n");
		else if (sum > n)  
			printf("Abundant\n");
		
		else 
			printf("Deficient\n");
		
		vtmp.clear();
	}

}

/*comment*/
//소수 처리를 안해줌