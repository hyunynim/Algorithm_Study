#include<cstdio>
#include<algorithm>
#include<stack>
#include<utility>
#include<vector>
using namespace std;
char msg[222222];

vector<pair<int, int>> ans, vtmp;
int abs(int a) { return a > 0 ? a : -a; }
int bFind(pair<int, int> p) {
	int l = 0;
	int r = ans.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if ((abs(ans[mid].first - p.second) == 1)
			|| (abs(ans[mid].second - p.first) == 1)
			||( (ans[mid].first <= p.first && p.first <= ans[mid].second)
			&& (ans[mid].first <= p.second && p.second <= ans[mid].second))
			|| ((p.first <= ans[mid].first && ans[mid].first <= p.second)
				&& (p.first <= ans[mid].second && ans[mid].second <= p.second)))
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
	scanf("%d %s", &n, msg);
	stack<int> s;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (msg[i] == '(') 
			s.push(i);
		else {
			if (s.size()) {
				vtmp.push_back({ s.top(), i });
				s.pop();
			}
		}
	}
	if (vtmp.empty()) {
		printf("0");
		return 0;
	}
	sort(vtmp.begin(), vtmp.end());
	ans.push_back(vtmp[0]);
	pair<int, int> pTmp;
	for (int i = 1; i < vtmp.size(); ++i) {
		int ind = bFind(vtmp[i]);
		if (ind == -1)
			ans.push_back(vtmp[i]);
		else {
			pTmp = { min(ans[ind].first, vtmp[i].first), max(ans[ind].second, vtmp[i].second) };
			ans[ind] = pTmp;
		}
	}
	for (auto & p : ans) {
		res = max(res, p.second - p.first + 1);
	}
	printf("%d", res);
}