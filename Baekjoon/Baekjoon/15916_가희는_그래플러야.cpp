#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int k;

bool chk(ll x1, ll x2, ll y1, ll y2) {
	ll a = y1 - y2;
	ll c = y1 + (y1 - y2)*x1;
	ll d = k;
	if (a + k == 0)
		return 0;
	long double ans = (long double)c / (a + k);
	if (ans - x1 >= 0 && x2 - ans >= 0)
		return 1;
	else
		return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> seq(n + 1);
	seq[0] = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &seq[i]);

	scanf("%d", &k);
	if (seq[1] == k) {
		printf("T");
		return 0;
	}
	for (int i = 2; i <= n; ++i) {
		if (chk(i - 1, i, seq[i - 1], seq[i])) {
			printf("T");
			return 0;
		}
	}
	printf("F");
}