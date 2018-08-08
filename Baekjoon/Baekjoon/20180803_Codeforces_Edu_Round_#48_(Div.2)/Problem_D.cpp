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
int a, b;
int cnt[2][111][32];
ll mat[111][111];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	stack<int> s;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		for (int j = 0; j < 32; ++j) {
			s.push(a % 2);
			a /= 2;
		}
		for (int j = 0; j < 32; ++j) {
			cnt[0][i][j] = s.top();
			s.pop();
		}
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		for (int j = 0; j < 32; ++j) {
			s.push(a % 2);
			a /= 2;
		}
		for (int j = 0; j < 32; ++j) {
			cnt[1][i][j] = s.top();
			s.pop();
		}
	}
}