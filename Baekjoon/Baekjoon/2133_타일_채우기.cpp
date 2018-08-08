#include<cstdio>
typedef long long ll;

ll d[31] = { 1, 0, 3};

int main() {
	for (int i = 3; i < 31; ++i) {
		if (i % 2) continue;
		else {
			for (int j = 2; j <= i; j += 2) {
				d[i] += 2 * d[i - j];
				if (j == 2)
					d[i] += d[i - j];
			}
		}
	}
	int n;
	scanf("%d", &n);
	for(int i = 1; i<=30; ++i)
		printf("%lld\n", d[i]);
}