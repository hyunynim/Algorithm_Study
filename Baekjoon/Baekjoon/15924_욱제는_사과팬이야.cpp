#include<cstdio>
typedef long long ll;
#define MOD ((int)1e9 + 9)
int n, m;

int map[3000][3000];
int d[3000][3000];

int main() {
	scanf("%d %d", &n, &m);
	char msg[3210];
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		for (int j = 0; j < m; ++j) {
			if (msg[j] == 'E')
				map[i][j] = 1;
			else if (msg[j] == 'S')
				map[i][j] = 2;
			else if (msg[j] == 'B')
				map[i][j] = 0;
			else
				map[i][j] = -1;
		}
	}
	d[n - 1][m - 1] = 1;
	ll ans = 1;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i == n - 1 && j == m - 1)
				continue;
			if (map[i][j] == 1)
				d[i][j] = d[i][j + 1];
			else if (map[i][j] == 2)
				d[i][j] = d[i + 1][j];
			else
				d[i][j] = d[i + 1][j] + d[i][j + 1];
			d[i][j] %= MOD;
			ans += d[i][j];
			ans %= MOD;
		}
	}
	printf("%lld", ans);
}