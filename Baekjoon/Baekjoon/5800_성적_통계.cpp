#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int n, tmp, sum = 0, maxgap = 0;
		vector<int> score;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			score.push_back(tmp);
			sum += tmp;
		}
		sort(score.begin(), score.end());
		for (int j = 1; j < n; ++j) {
			if (score[j] - score[j - 1] > maxgap) {
				maxgap = score[j] - score[j - 1];
			}
		}
		printf("Class %d\n", i + 1);
		printf("Max %d, Min %d, Largest gap %d\n", *(score.end() - 1), *score.begin(), maxgap);
		score.clear();
	}
}