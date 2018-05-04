#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n, tmp;
	vector<int> seq;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	int maxSub = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (seq[j] <= seq[j-1]) {
				if (seq[j - 1] - seq[i] > maxSub) {
					maxSub = seq[j - 1] - seq[i];
				}
				i = j;
			}
			if (j == n - 1) {
				if (seq[j] - seq[i] > maxSub) {
					maxSub = seq[j] - seq[i];
				}
			}
		}
	}
	printf("%d", maxSub);
}