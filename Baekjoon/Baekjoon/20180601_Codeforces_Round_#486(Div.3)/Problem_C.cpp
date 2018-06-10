#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<string>
using namespace std;

int main() {
	vector<pair<int ,int>> seq[2];
	int sum[2] = { 0 };
	for (int i = 0; i < 2; ++i) {
		int n;
		scanf("%d", &n);
		int tmp;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			seq[i].push_back(make_pair(tmp, i));
			sum[i] += tmp;
		}
		sort(seq[i].begin(), seq[i].end());
	}
	int i = 0, j = 0, sub = sum[1] - sum[0];
	while (i < seq[0].size() && j < seq[1].size()) {
		if (sub == seq[1][j] - seq[0][i]) {
			printf("YES\n");
			printf("")
			}
	}
}