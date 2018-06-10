#include<cstdio>

int main() {
	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t) {
		int n;
		scanf("%d", &n);
		printf("%d\n", ((n / 2) + 1)*((n / 2) + 1));

	}
}