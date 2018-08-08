#include<cstdio>
#include<vector>
#include<math.h>
typedef long long ll;
using namespace std;


int main() {
	ll n;
	scanf("%lld", &n);
	if (n <= 500000) {
		ll ans = 0;
		for(int i = 1; i<=n; ++i)
			ans += n / i + (n % i ? 1 : 0);
		printf("%lld", ans);
		return 0;
	}

	ll ans = 0;
	int i;
	for (i = 1; i*i <= n; ++i) {
		ans += n / i + (n % i ? 1 : 0);
	}
	int iTmp = i;
	ans += (n / i) + (n%i ? 1 : 0);
	while (1) {
		int tmp = n / i;
		if (tmp == 1) {
			break;
		}
		int tmp2 = n % (tmp - 1) == 0 ? n / (tmp - 1) - 1 : n / (tmp - 1);
		ans += (tmp2 - i)*tmp;
		i = tmp2;
	}
	printf("%lld", ans + 1);
	
}