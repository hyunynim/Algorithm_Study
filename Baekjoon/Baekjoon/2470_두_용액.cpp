#include<cstdio>
#include<vector>
#include<algorithm>
#define INT_MAX 2100000000
using namespace std;

int ABS(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	
	vector<int>::iterator left = seq.begin(), right = seq.end() - 1, minLeft, minRight;
	int minSum = INT_MAX;
	while (left < right) {
		if (minSum > ABS(*left + *right)) {
			minSum = ABS(*left + *right);
			minLeft = left;
			minRight = right;
		}
		if (ABS((*(left + 1)) + (*right)) > ABS((*left) + (*(right - 1))))
			--right;
		else
			++left;
	}
	printf("%d %d", *minLeft, *minRight);
}