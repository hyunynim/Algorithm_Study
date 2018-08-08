#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
typedef long long ll;
using namespace std;
int n, k;
int s, e;
vector<ll> num;
vector<int> adj[1 << 10];
int cache[1 << 10];
bool chk[1 << 10];
int v[1 << 10];

void print(int s) {
	printf("%d ", s + 1);
	if (v[s] == -1)
		return;

	else
		print(v[s]);
}

int DP(int start) {
	if (start == e) 
		return 0;
	int & ans = cache[start];
	if (ans != (1 << 10))
		return ans;
	ans = 1 << 10;
	chk[start] = 1;
	for (int i = 0; i < adj[start].size(); ++i) {
		if (!chk[adj[start][i]]) {
			int tmp = DP(adj[start][i]) + 1;
			if (ans > tmp) {
				ans = tmp;
				v[start] = adj[start][i];
			}
			ans = min(ans, DP(adj[start][i]) + 1);
		}
	}
	return ans;
}

int HamingDistance(ll a, ll b) {
	int res = 0;
	ll c = a ^ b;
	for (int i = 0; i < k; ++i) {
		if (c & (1 << i))
			res++;
	}
	return res;
}

int main() {
	fill(cache, cache + (1 << 10), 1 << 10);
	memset(v, -1, sizeof(v));
	int n = 3;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int j = k;
		int tmp;
		ll p = 0;
		while (j--) {
			scanf("%1d", &tmp);
			if (tmp)
				p |= (1 << j);
		}
		num.push_back(p);
	}
	for (int i = 0; i < num.size(); ++i) {
		for (int j = 0; j < num.size(); ++j) {
			if (HamingDistance(num[i], num[j]) == 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	scanf("%d %d", &s, &e);
	--s; --e;
	if (DP(s) != (1 << 10))
		print(s);
	else
		printf("-1");
}

/*comment*/
//code의 길이가 늘어나는 경우만 생각했음
//code에 따라 길이가 줄어들었다가 늘어나야 할 필요도 있을 것 같음
//-> iteration 말고 recursion으로 다시 ㄱㄱ 일단 코드잼 끝나고 다시 생각해보자
//갈아엎음