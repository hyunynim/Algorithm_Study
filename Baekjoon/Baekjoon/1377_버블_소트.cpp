#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = -987654321;
int n;
int num[500002];
vector<int> v;
int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; ++i) {
		scanf("%d", &num[i]);
		v.push_back(num[i]);
	}
	sort(v.begin(), v.end());
	int ans = INF;
	for (int i = 0; i<n; ++i) {
		int idx = upper_bound(v.begin(), v.end(), num[i]) - v.begin() - 1;
		int k = i - idx;
		ans = max(ans, k);
	}
	printf("%d",(ans>=n-1?n-1:ans)+1);
}