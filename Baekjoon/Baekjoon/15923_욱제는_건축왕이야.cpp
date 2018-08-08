#include<vector>
#include<utility>
#include<algorithm>
#include<cstdio>

using namespace std;

int ABS(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> seq;
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		seq.push_back({ a,b });
	}
	int res = ABS(seq[n-1].first - seq[0].first) + ABS(seq[n-1].second - seq[0].second);
	for (int i = 1; i < n; ++i) {
		res += ABS(seq[i].first - seq[i - 1].first) + ABS(seq[i].second - seq[i - 1].second);
	}
	printf("%d", res);
}