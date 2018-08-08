#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
#define INF 1e9
using namespace std;

int cache[1234];
vector<int> jump;
int n, tmp;

int jumpJump(int start) {
	if (start >= n)
		return INF;
	if (start == n - 1)
		return 0;
	else {
		int & ans = cache[start];
		if (ans != -1)
			return ans;
		int res = INF;
		for (int i = jump[start]; i > 0; --i) 
			res = min(res, jumpJump(start + i) + 1);
		ans = res;
		return ans;
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		jump.push_back(tmp);
	}
	int ans = jumpJump(0);
	printf("%d", ans >= 1e9 ? -1 : ans);
}