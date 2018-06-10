#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, m, tmp;
	scanf("%d %d", &n, &m);
	int max1 = 0, max2 = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		max1 = max(max1, tmp);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &tmp);
		max2 = max(max2, tmp);
	}
	printf("%d", max1 + max2);
}