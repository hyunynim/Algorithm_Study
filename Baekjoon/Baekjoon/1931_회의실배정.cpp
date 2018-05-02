#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector <pair<int, int>> time;
	scanf("%d", &n);
	int s, e;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &s, &e);
		time.push_back(make_pair(e, s));
	}
	sort(time.begin(), time.end());

	int earliest = 0, picked = 0;

	for (int i = 0; i < time.size(); ++i) {
		int begin = time[i].second, end = time[i].first;
		if (earliest <= begin) {
			earliest = end;
			++picked;
		}
	}
	printf("%d", picked);
}