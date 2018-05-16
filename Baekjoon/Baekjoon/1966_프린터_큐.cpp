#include<queue>
#include<utility>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	queue<pair<int, int>> printer;
	vector<int> MAX;
	int t;
	int n, m, tmp;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			printer.push(make_pair(tmp, i));
			MAX.push_back(tmp);
		}
		sort(MAX.begin(), MAX.end(), greater<int>());
		int res = 0;
		while (1) {
			while (printer.front().first != MAX[res]) {
				printer.push(printer.front());
				printer.pop();
			}
			res++;
			if (printer.front().second == m)
				break;
			printer.pop();
		}
		printf("%d\n", res);

		while (printer.size())
			printer.pop();
		MAX.clear();
	}
}