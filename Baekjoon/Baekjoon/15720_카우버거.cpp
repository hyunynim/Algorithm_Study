#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int main() {
	int a[3], tmp;
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	vector<int> price[3];
	int res[2] = { 0 };
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < a[i]; ++j) {
			scanf("%d", &tmp);
			price[i].push_back(tmp);
			res[0] += tmp;
		}
		sort(price[i].begin(), price[i].end(), greater<int>());
	}
	res[1] = res[0];

	for (int i = 0; i < min(a[0], min(a[1], a[2])); ++i) {
		res[1] -= (price[0][i] + price[1][i] + price[2][i]) * 0.1;
	}
	printf("%d\n%d", res[0], res[1]);
}