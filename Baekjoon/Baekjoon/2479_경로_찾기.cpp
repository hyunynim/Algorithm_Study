#include<cstdio>

bool edge[1001][1001] = { 0 };

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j)
			scanf("%1d", &edge[i][j]);
	}
	scanf("%d %d", &n, &k);
	printf("zz");
}