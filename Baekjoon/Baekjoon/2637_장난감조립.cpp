#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
typedef long long ll;
using namespace std;
vector<pair<ll, ll>> part[102];
int n, m;

ll ans[123];
bool chk[123];
void DFS(int start, int cnt) {
	if (!chk[start]) {
		ans[start] += cnt;
	}
	else {
		for (int i = 0; i < part[start].size(); ++i) {
			DFS(part[start][i].first, cnt * part[start][i].second);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		ll a, b, w;
		scanf("%lld %lld %lld", &a, &b, &w);
		part[a].push_back({ b, w });
		chk[a] = 1;
	}
	DFS(n, 1);
	for (int i = 1; i <= n; ++i) {
		if (!chk[i]) {
			printf("%d %lld\n", i, ans[i]);
		}
	}
}