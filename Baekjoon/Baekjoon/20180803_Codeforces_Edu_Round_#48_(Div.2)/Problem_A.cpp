#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<utility>
#include<functional>
#include<string.h>
#include<string>

using namespace std;
typedef long long ll;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	vector<int> ans;
	int r = 0;
	int tmp;
	for (int i = 0; i < n; ++i) {
		if (r) {
			if (seq[i] >= r) {
				seq[i] -= r;
				tmp = seq[i] / m;
				ans.push_back(tmp + 1);
				r = m - seq[i] % m;
			}
			else {
				ans.push_back(0);
				r -= seq[i];
			}
		}
		else {
			tmp = seq[i] / m;
			ans.push_back(tmp);
			r = m - seq[i] % m;
		}
	}
	for (int i : ans)
		printf("%d ", i);
}