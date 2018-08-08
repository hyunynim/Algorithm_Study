#include<cstdio>
typedef long long ll;
ll d[65][11];

int main() {
	for (int i = 0; i < 10; ++i) {
		d[1][i] = 1;
		d[1][10] += d[1][i];
		d[2][i] = 10 - i;
		d[2][10] += d[2][i];
	}
	for (int i = 3; i < 65; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j)
				d[i][j] = d[i][j - 1] - d[i - 1][j- 1];
			else
				d[i][j] = d[i - 1][10];
			d[i][10] += d[i][j];
		}
	}
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		printf("%lld\n", d[n][10]);
	}
}