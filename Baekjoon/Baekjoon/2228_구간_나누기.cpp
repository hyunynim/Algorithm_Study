#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> seq, sum;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	seq.resize(n);
	sum.resize(n);
	int tmp = 0;
	int ans = -987654321;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		tmp += seq[i];
		sum[i] = tmp;
	}
	
	if (m == 1) {
		printf("%d", sum.back());
	}
	else if (m == 2) {
		for (int i = 0; i < n - 1; ++i) {
			ans = max(ans, sum[i]);
		}
		for (int i = 1; i < n; ++i)
			ans = max(ans, sum.back() - sum[i - 1]);
	}
	else {
		for (int i = n - (m - 1); i >= 1; --i) {
			for (int j = 0; j + i < n; ++j)
				ans = max(ans, sum[i+j] - sum[j]);
		}
	}
	printf("%d", ans);
}