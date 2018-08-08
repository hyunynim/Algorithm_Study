#include<cstdio>
#include<vector>
using namespace std;
bool chk[123][1010];
int main() {
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	chk[0][s] = 1;
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (chk[i][j]) {
				if (j - seq[i] >= 0)
					chk[i + 1][j - seq[i]] = 1;
				if (j + seq[i] <= m)
					chk[i + 1][j + seq[i]] = 1;
			}
		}
	}
	for (int i = 0; i <= m; ++i) {
		if (chk[n][i])
			ans = i;
	}
	printf("%d", ans);
}