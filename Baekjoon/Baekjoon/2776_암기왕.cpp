#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m, tmp;
		vector<int> seq1;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			seq1.push_back(tmp);
		}
		sort(seq1.begin(), seq1.end());
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			scanf("%d", &tmp);
			printf("%d\n", binary_search(seq1.begin(), seq1.end(), tmp));
		}
	}
}