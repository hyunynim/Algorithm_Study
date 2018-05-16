#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
#define pb push_back

typedef long long ll;
using namespace std;

vector<ll> w;
int n;
int maxCnt;

int cache[1000000];

int Pick(ll weight, int prev) {
	int next = weight == 0 ? 0 : prev + 1;
	if (next >= n)
		return 0;
	else {
		int & ref = cache[next];
		if (ref != -1)
			return ref;
		ref = 0;
		for (int i = next; i < n; ++i) {
			if (weight <= w[i] * 6) {
				ref = max(ref, Pick(weight + w[i], i) + 1);
			}
		}
		return ref;
	}
}

int main() {
	int t;
	ll tmp;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		memset(cache, -1, sizeof(cache));
		maxCnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &tmp);
			w.pb(tmp);
		}
		printf("Case #%d: ", tt + 1);
		maxCnt = Pick(0LL, 0);
		printf("%d\n", maxCnt);
		w.clear();
	}
}