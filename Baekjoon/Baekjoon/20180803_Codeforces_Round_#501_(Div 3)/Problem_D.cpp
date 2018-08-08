#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;

int food[123];

int wh(bool f) {
	return f ? -1 : 1;
}

int main() {
	ll n, k, s;
	scanf("%lld %lld %lld", &n, &k, &s);

	if ((n - 1) * k < s || k > s)
		printf("NO");
	else {
		ll cur = 1;
		bool f = 0; //0:r 1:l
		puts("YES");
		n = s / k;
		if (s % k) {
			cur += (s - (s / k) * (k - 1));
			printf("%lld ", cur);
			s -= (s - (s / k) * (k - 1));
			f = f ? 0 : 1;
		}
		while (s) {
			if (s >= n) {
				s -= n;
				printf("%lld ", cur + n * wh(f));
				cur += n * wh(f);
				f = f ? 0 : 1;
			}
			else {
				while (s < n && n > 0)
					--n;
			}
		}
	}
}