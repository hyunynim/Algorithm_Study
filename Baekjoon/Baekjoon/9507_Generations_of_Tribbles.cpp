#include<cstdio>
typedef long long ll;

ll d[123] = { 1, 1, 2, 4 };

int main() {
	for (int i = 4; i < 68; ++i)
		d[i] = d[i - 1] + d[i - 2] + d[i - 3] + d[i - 4];
	int n, t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
}