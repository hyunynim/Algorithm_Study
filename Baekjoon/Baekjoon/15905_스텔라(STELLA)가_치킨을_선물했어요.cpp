#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<functional>

using namespace std;

int main() {
	int n, a, b;
	vector<pair<int, int>> scoreboard;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		scoreboard.push_back({ a, b });
	}
	sort(scoreboard.begin(), scoreboard.end(), greater<pair<int, int>>());

	int rank5 = scoreboard[4].first;
	int score = scoreboard[4].second;
	int ans = 0;
	for (int i = 5; i < scoreboard.size(); ++i) {
		if (scoreboard[i].first == rank5 && scoreboard[i].second < score)
			++ans;
	}
	printf("%d", ans);
}