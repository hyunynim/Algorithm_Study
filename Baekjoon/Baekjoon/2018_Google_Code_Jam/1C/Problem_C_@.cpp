#include <iostream>
#include <string.h>

typedef long long ll;

ll cache[1001], weight[100001];

int n;
ll Lis(ll, ll);
ll max(ll a, ll b) {
	return a > b ? a : b;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int asdf = 0; asdf < t; ++asdf) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &weight[i]);
		}
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			res = max(res, Lis(weight[i], i));
		}
		printf("Case #%d: %lld\n", asdf + 1, res);
	}
}

ll Lis(ll curw, ll start) {
	if (start >= n)
		return 0;
	ll & ref = cache[start];
	if (ref != -1)
		return ref;
	else {
		ref = 1;
		for (int i = start + 1; i < n; ++i) {
			if (curw <= weight[i]*6)
				ref = max(ref, Lis(curw + weight[i], i) + 1);
		}
		return ref;
	}
}