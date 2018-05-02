#include <cstdio>
#include <algorithm>

using namespace std;
int main() {
	int a[5] = { 0 };
	int res= 0;
	for (int i = 0; i < 5; ++i) {
		scanf("%d", &a[i]);
		res += a[i];
	}
	sort(a, a + 5);
	printf("%d\n%d", res / 5, a[2]);
} 