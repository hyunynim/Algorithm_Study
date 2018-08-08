#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> seq;
	vector<pair<int, int>> seq2;
	seq.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		seq2.push_back(make_pair(seq[i], i));
	}

	sort(seq2.begin(), seq2.end(), greater<pair<int, int>>());
	vector<pair<int, int>> vtmp;
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += seq2[i].first;
		int ind = find(seq.begin(), seq.end(), seq2[i].first) - seq.begin();
		seq[ind] = -1;
		vtmp.push_back(make_pair(ind, seq2[i].first));
	}
	sort(vtmp.begin(), vtmp.end());
	printf("%d\n", ans);

	if (vtmp.size() == 1) {
		printf("%d", seq.size());
	}
	else if (vtmp.size() == 2) {
		int ans = vtmp[0].first + 1;
		printf("%d %d", ans, seq.size() - ans);
	}
	else {
		if (vtmp[0].first != 0) {
			printf("%d ", vtmp[0].first + 1);
			for (int i = 1; i < vtmp.size() - 1; ++i)
				printf("%d ", vtmp[i].first - vtmp[i - 1].first);
			printf("%d", seq.size() - vtmp.back().first + vtmp.back().first - vtmp[vtmp.size() - 2].first - 1);
		}
		else {
			for (int i = 1; i < vtmp.size(); ++i)
				printf("%d ", vtmp[i].first - vtmp[i - 1].first);
			printf("%d", seq.size() - vtmp.back().first);
		}
	}

}