#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main() {
	int n, x, y;
	scanf("%d", &n);
	vector<pair<int, int>> seq, tmp, ans;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		seq.push_back({ x, y });
	}
	for (int i = 0; i < seq.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < seq.size(); ++j) {
			if (i == j)
				continue;
			if (seq[i].first < seq[j].first && seq[i].second < seq[j].second)
				++cnt;
		}
		tmp.push_back({ cnt, i });
	}
	for (int i = 0; i < tmp.size(); ++i)
		printf("%d ", tmp[i].first + 1);
}