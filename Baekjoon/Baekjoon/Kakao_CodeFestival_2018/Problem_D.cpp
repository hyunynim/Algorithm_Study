#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional>
#include<string>
#include<queue>
#include<stack>
#include<string.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
vector<PL> pos;
int st, de;
bool chk[250001];
int n, q;
vector<P> canGo[2][250001];
ll ABS(ll a) {
	return a > 0 ? a : -a;
}

bool direct(int a1, int a2, ll x) {
	ll x1, y1, tmp, x2, y2;
	tie(x1, y1) = pos[a1];
	tie(x2, y2) = pos[a2];
	
	return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) <= x * x || ABS(x2 - x1) <= x || ABS(y2 - y1) <= x;
}

bool go(int cur, ll x) {
	if (direct(cur, de, x))
		return 1;
	for (int i = 0; i < canGo[0][cur].size(); ++i) {
		if (canGo[0][cur][i].first == de && canGo[0][cur][i].second <= x) {
			canGo[0][cur][i].second = max(canGo[0][cur][i].second, (int)x);
			return 1;
		}
	}
	for (int i = 0; i < canGo[1][cur].size(); ++i) {
		if (canGo[1][cur][i].first == de && canGo[1][cur][i].second > x) {
			canGo[1][cur][i].second = min(canGo[1][cur][i].second, (int)x);
			return 0;
		}
	}
	chk[cur] = 1;
	for (int i = 0; i < n; ++i) {
		if (i == cur)
			continue;
		if (!chk[i] && direct(cur, i, x)) {
			if(go(i, x)) return 1;
		}
	}
	return 0;
}

int main() {
	ll x, y;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", &x, &y);
		pos.push_back({ x, y });
	}

	for (int i = 0; i < q; ++i) {
		int a, b;
		memset(chk, 0, sizeof(chk));
		scanf("%d %d %lld", &a, &b, &x);
		--a; --b;
		de = b;
		if (go(a, x)) {
			canGo[0][a].push_back({ b, x });
			canGo[0][b].push_back({ a, x });
			puts("YES");
		}
		else {
			canGo[1][a].push_back({ b, x });
			canGo[1][b].push_back({ a, x });
			puts("NO");
		}
	}
}
