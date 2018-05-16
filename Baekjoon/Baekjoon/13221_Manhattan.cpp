#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<functional>

using namespace std;
int ABS(int a) {
	return a > 0 ? a : -a;
}
int main() {
	vector<pair<int, pair<int, int>>> res;
	int x, y, n;
	scanf("%d %d %d", &x, &y, &n);
	int tx, ty;
	int MIN = 2100000000, minIndex = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &tx, &ty);
		res.push_back(make_pair(ABS(tx - x) + ABS(ty - y), make_pair(tx, ty)));
		if (res[i].first < MIN) {
			MIN = res[i].first;
			minIndex = i;
		}
	}
	printf("%d %d", res[minIndex].second.first, res[minIndex].second.second);

}