#include<cstdio>
#include<vector>
#define pb push_back

typedef long long ll;
using namespace std;

vector<ll> w;
int n;
int max;

void Pick(ll weight, int prev, int curCnt) {
	int next = weight == 0 ? 0 : prev + 1;
	for (int i = next; i < n; ++i) {
		if (weight <= w[i] * 6) {
			if (curCnt > max)
				max = curCnt;
			weight += w[i];
			Pick(weight, i, curCnt + 1);
			weight -= w[i];
		}

	}
}

int main() {
	int t;
	ll tmp;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		max = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &tmp);
			w.pb(tmp);
		}
		printf("Case #%d: ", tt + 1);
		Pick(0LL, 0, 0);
		printf("%d\n", max + 1);
		w.clear();
	}
}