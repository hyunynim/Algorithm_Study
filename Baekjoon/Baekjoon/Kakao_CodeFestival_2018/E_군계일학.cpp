#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int d[123456];

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);

	d[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (seq[i - 1] + 1 == seq[i])
			d[i] = d[i - 1] + 1;
	}
	int ans = 0;
	for (int i = 0; i < seq.size(); ++i)
		ans = max(d[i], ans);
	printf("%d", ans);
}