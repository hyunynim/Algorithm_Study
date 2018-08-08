#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector<int> seq;
int d[512][512];
int n;

int go(int s, int e) {
	if (s > e || s < 0 || e >= n)
		return 0;
	if (s == e)
		return seq[e];
	int & ans = d[s][e];
	if (ans != -1)
		return ans;
	ans = 987654321;
	int sum = 0;
	for (int i = s; i <= e; ++i)
		sum += seq[i];
	for (int i = s; i < e; ++i) {
		ans = min(ans, go(s, i) + go(i + 1, e) + sum);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		seq.clear();
		memset(d, -1, sizeof(d));
		scanf("%d", &n);
		seq.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &seq[i]);
		printf("%d\n", go(0, n - 1));
	}
}