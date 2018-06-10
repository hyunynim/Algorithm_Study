#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> score[234];
	int tmp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &tmp);
			score[i].push_back(tmp);
		}
	}
	int res[234] = { 0 };
	for (int i = 0; i < 3; ++i) {
		int check[101] = { 0 };
		for (int j = 0; j < n; ++j) {
			check[score[j][i]]++;
		}
		for (int j = 0; j < n; ++j) {
			if (check[score[j][i]] == 1)
				res[j] += score[j][i];
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", res[i]);
}