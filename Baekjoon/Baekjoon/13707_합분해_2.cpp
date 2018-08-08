#include<cstdio>
#include<algorithm>
using namespace std;
#define MOD 1000000000LL
typedef long long ll;
ll d[3][5001];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i < 5001; ++i) {
		d[0][i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			d[1][j] = d[1][j - 1] + d[0][j];
			d[1][j] %= MOD;
		}
		swap(d[1], d[0]);
	}
	printf("%lld", d[0][k]);
}