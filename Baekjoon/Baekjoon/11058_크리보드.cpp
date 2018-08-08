#include<cstdio>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
int n;
ll d[123];


ll go(int s) {
	if (s < 0)
		return 0;
	if(s <= 6)
		return s;

	ll & ans = d[s];
	if (ans != -1)
		return ans;
	ans = go(s - 1) + 1;
	if (s > 1) {
		for (int j = 1; j < s - 1; ++j)
			ans = max(ans, go(s - 2 - j) * (j+1));
	}
	return ans;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	printf("%lld", go(n));
}