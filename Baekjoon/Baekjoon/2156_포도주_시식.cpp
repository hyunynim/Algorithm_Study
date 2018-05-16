#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

#define INF -987654321
vector<int> seq;
int cache[3][10001];
int n, tmp;

int dp(int cnt, int start) {
	if (start >= n)
		return 0;
	int & ref = cache[cnt][start];
	if (ref != -1)
		return ref;
	ref = seq[start];
	int tmp = 0;
	if (cnt == 1) {
		tmp = max(tmp, dp(2, start + 1));
	}
	else if (cnt == 2);
	for (int i = start + 2; i <= n; ++i)
		tmp = max(tmp, dp(1, i));
	ref += tmp;
	return ref;
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	int res = dp(1, 0);
	res = max(res, dp(1, 1));
	printf("%d\n", res);	
}

/*comment*/
//시간초과
//memoization 적용 방법에 대해 고민
//cnt == 3 을 base case로 처리하려 했는데 뭔가 자꾸 꼬여서 cnt가 3으로 넘어가는 일이 없도록 함