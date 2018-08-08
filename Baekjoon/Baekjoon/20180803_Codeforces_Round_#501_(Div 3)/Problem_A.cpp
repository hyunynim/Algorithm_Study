#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;
bool chk[123];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> l(n), r(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &l[i], &r[i]);
		for (int j = l[i]; j <= r[i]; ++j)
			chk[j] = 1;
	}
	vector<int> ans;
	for (int i = 1; i <= m; ++i) {
		if (!chk[i])
			ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (int i : ans)
		printf("%d ", i);
}