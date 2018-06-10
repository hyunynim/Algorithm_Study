#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	int seqMax = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		if (seq[i] > seqMax) {
			seqMax = seq[i];
			maxIndex = i;
		}
	}
	int res = 0;
	int curMax = -1;
	for (int i = 0; i < seq.size(); ++i) {
		if (seq[i] > curMax) {
			++res;
			curMax = seq[i];
		}
	}
	printf("%d\n", res);
	res = 0;
	curMax = -1;
	for (int i = seq.size() - 1; i >= 0; --i) {
		if (seq[i] > curMax) {
			++res;
			curMax = seq[i];
		}
	}
	printf("%d", res);
}

/*comment*/
//처음에 최댓값까지만 탐색하게 했으나 최댓값이 2개 이상인 경우 제대로 동작 안함