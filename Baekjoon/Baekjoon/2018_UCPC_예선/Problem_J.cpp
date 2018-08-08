#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int n;
int main() {
	vector<int> seq[2];
	scanf("%d", &n);
	seq[0].resize(n);
	seq[1].resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[0][i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[1][i]);
	int i1 = 0, i2 = 0;
	int cnt[2][30] = { 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 30; ++j) {
			if (seq[0][i] & (1 << j))
				++cnt[0][j];
			if (seq[1][i] & (1 << j))
				++cnt[1][j];
		}
	}
	int pow2 = 1;
	ll ans = 0;
	for (int i = 0; i < 30; ++i) {
		ans += (cnt[0][i] * cnt[1][i]) * pow2;
		ans %= 1999;
		pow2 *= 2;
	}
	printf("%lld", ans);
}