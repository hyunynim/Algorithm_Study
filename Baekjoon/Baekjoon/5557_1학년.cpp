#include<cstdio>
typedef long long ll;
ll d[123][22];

int main() {
	int seq[123];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	d[0][seq[0]] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= 20; ++j) {
			if (j - seq[i] >= 0)
				d[i][j - seq[i]] += d[i - 1][j];
			if (j + seq[i] <= 20)
				d[i][j + seq[i]] += d[i - 1][j];
		}
	}
	printf("%lld", d[n - 2][seq[n - 1]]);
}