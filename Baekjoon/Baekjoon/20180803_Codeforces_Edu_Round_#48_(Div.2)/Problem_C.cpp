#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<utility>
#include<functional>
#include<string.h>
#include<string>

typedef long long ll;
using namespace std;
vector<int> a[2];
vector<int> tw;
ll ans[2];
int n;

ll calc(int x, int y, int cnt) {
	int c = 0;
	ll res = 0;
	for (int i = y; i < n; ++i) {
		res += a[x][i] * (cnt + c);
		res += a[1 - x][i] * (n - c);
		++c;
	}
	return res;
}

ll go(int x, int y, int prev, int cnt) {
	if (y == n - 1) {
		if (prev == 2)
			return cnt * a[x][y] + (cnt + 1) * a[1 - x][y];
		else
			return cnt * a[x][y];
	}
	ll tmp = cnt * a[x][y];
	if (prev == 0 || prev == 1) {//d
		tmp += go(x, y + 1, 2, cnt + 1);
		tmp = max(tmp, calc(x, y, cnt));
	}
	else if (prev == 2){//r
		if (a[1 - x][y] == a[x][y + 1]) {
			tmp = go(1 - x, y, x, cnt + 1);
			tmp = max(tmp, calc(x, y, cnt));
		}
		else if (a[1 - x][y] > a[x][y + 1])
			tmp = calc(x, y, cnt);
		else
			tmp = go(1 - x, y, x, cnt + 1);
	}
	else {
		if (a[1][0] == a[0][1]) {
			tmp += min(go(1, 0, 0, cnt + 1), go(0, 1, 2, cnt + 1));
		}
		else if (a[1][0] > a[0][1])
			tmp += go(0, 1, 2, cnt + 1);
		else
			tmp += go(1, 0, 0, cnt + 1);
	}
	return tmp;
}

int main() {
	scanf("%d", &n);
	a[0].resize(n);
	a[1].resize(n);
	for (int j = 0; j < 2; ++j)
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[j][i]);
	for (int i = 0; i < n; ++i)
		ans[0] += a[0][i] * i;
	for (int i = n - 1; i >= 0; --i)
		ans[0] += a[1][i] * (2 * n - i - 1);

	tw.push_back(a[0][0]);
	vector<ll> sum[2];
	sum[0].push_back(a[0][0]);
	sum[1].push_back(a[1][0]);
	for (int i = 1; i < n; ++i) {
		tw.push_back(a[i % 2][i - 1]);
		tw.push_back(a[i % 2][i]);
		sum[0].push_back(sum[0].back() + a[0][i]);
		sum[1].push_back(sum[1].back() + a[1][i]);
	}
	tw.push_back(a[n % 2].back());
	
	/*
	for (int i = 1; i < tw.size(); i += 2) {
		ll tmp = 0;
		int cnt = 0;
		for (int j = 0; j <= i; ++j) {
			tmp += (cnt++) * tw[j];
		}
		for (int k = i/2 + 1; k < n; ++k)
			tmp += a[i % 4 == 1][k] * (cnt++);
		for (int k = n - 1; k >= i / 2 + 1; --k)
			tmp += a[i % 4 != 1][k] * (cnt++);
		ans = max(tmp, ans);
	}
	*/
	printf("%lld", go(0, 0, -1, 0));
}