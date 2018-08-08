#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;

ll graph[23][23];
ll n, m, k;

int go(int x, int y, ll num) {
	if (x >= m || y >= n)
		return 987654321;
	num ^= graph[y][x];
	int ans = 1;
	ans += min(go(x + 1, y, num), go(x, y + 1, num));
	return ans;
}

int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> graph[i][j];
	}
	cout << go(0, 0, 0);
}