#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

#define MUL 100000000

using namespace std;

typedef long long ll;

int food[123];

int main() {
	ll n, m, tmp;
	cin >> n >> m;
	m *= MUL;
	vector<ll> seq[2];
	seq[0].resize(n);
	seq[1].resize(n);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> seq[i][j];
	}
	vector<ll> f;
	f.push_back(seq[1][0]);
	for (int i = n - 1; i >= 0; --i) {
		f.push_back(seq[0][i]);
		f.push_back(seq[1][i]);
		if (seq[0][i] == 1 || seq[1][i] == 1) {
			printf("-1");
			return 0;
		}
	}
	f.pop_back();

	ll ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
			tmp = (m + ans) / (f[i] - 1);
			ans += tmp;
	}
	cout << ans / MUL << '.' << ans % MUL;
	
}