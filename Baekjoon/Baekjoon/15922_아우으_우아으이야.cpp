#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
typedef long long ll;
using namespace std;
vector<pair<int, int>> seq;
vector<pair<int, int>> ans;

int bFind(pair<int, int> p) {
	int l = 0;
	int r = ans.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if ((ans[mid].first <= p.first && p.first <= ans[mid].second)
			|| (ans[mid].first <= p.second && p.second <= ans[mid].second))
			return mid;

		if (ans[mid].second < p.first)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		seq.push_back({ a, b });
	}

	ans.push_back(seq[0]);
	pair<int, int> pTmp;
	for (int i = 1; i < seq.size(); ++i) {
		int ind = bFind(seq[i]);
		if (ind == -1)
			ans.push_back(seq[i]);
		else {
			pTmp = { min(ans[ind].first, seq[i].first), max(ans[ind].second, seq[i].second) };
			ans[ind] = pTmp;
		}
	}

	ll res = 0;
	for (int i = 0; i < ans.size(); ++i)
		res += ans[i].second - ans[i].first;
	printf("%lld", res);
}