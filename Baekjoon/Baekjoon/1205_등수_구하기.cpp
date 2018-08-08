#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
#include<utility>
using namespace std;

vector<pair<int, int>> seq;

int main() {
	int n, score, p;
	scanf("%d %d %d", &n, &score, &p);
	int a;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		seq.push_back({ a, i });
	}
	seq.push_back({ score, -1 });

	sort(seq.begin(), seq.end(), greater<pair<int, int>>());
	if (seq[0].first == score) {
		int i = 1; 
		for (; i < seq.size() && seq[i].first == seq[i - 1].first; ++i);
		if (i <= p)
			printf("1");
		else
			printf("-1");
		return 0;
	}
	int rank = 1;
	int cnt = 1;
	for (int i = 1; i < p && i < seq.size(); ++i) {
		if (seq[i].first == seq[i - 1].first) {
			++cnt;
		}
		else {
			rank += cnt;
			cnt = 1;
		}
		if (seq[i].first == score && seq[i].second == -1) {
			printf("%d", rank);
			return 0;
		}
	}
	printf("-1");
}