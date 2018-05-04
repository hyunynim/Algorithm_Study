#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
	int n;
	vector<pair<int, int>> pos;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		pos.push_back(make_pair(b, a));
	}
	sort(pos.begin(), pos.end());

	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", pos[i].second, pos[i].first);
	}
}