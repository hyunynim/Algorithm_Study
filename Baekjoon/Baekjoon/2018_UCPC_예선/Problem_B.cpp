#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional>
typedef long long ll;
using namespace std;

vector<ll> seq;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	seq.resize(n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
	}
	ll tmp = 0;
	for (int i = 0; i < m; ++i) {
		sort(seq.begin(), seq.end());
		tmp = seq[0] + seq[1];
		seq[0] = tmp;
		seq[1] = tmp;
	}
	for (int i = 0; i < n; ++i)
		ans += seq[i];
	printf("%lld", ans);
}

/*comment*/
//6 4 1 1 1 1 1 1 ´ä: 14 ¿À´ä: 16