#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int n, m;
vector<pair<int, int>> seq;
bool day[1234];
int ans = 12345;

void cnt() {
	int sum = 0;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (day[i]) {
			res = max(res, sum);
			sum = 0;
		}
		else
			++sum;
	}
	res = max(res, sum);
	ans = min(ans, res);
}

void go(int pick, int prev) {
	int next = pick ? prev + 1 : 0;
	for (int i = next; i < seq.size(); ++i) {
		if (pick == 0 || seq[prev].second < seq[i].first) {
			fill(day + seq[i].first, day + seq[i].second + 1, 1);
			cnt();
			go(pick + 1, i);
			fill(day + seq[i].first, day + seq[i].second + 1, 0);
		}
	}

}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		seq.push_back({ a,b });
	}
	sort(seq.begin(), seq.end());

	go(0, 0);
	printf("%d", ans - 1);
}