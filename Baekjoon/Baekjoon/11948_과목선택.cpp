#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a[4];
	int b[2];
	for (int i = 0; i < 4; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < 2; ++i)
		scanf("%d", &b[i]);
	sort(a, a + 4);
	sort(b, b + 2);
	int res = 0;
	for (int i = 1; i < 4; ++i)
		res += a[i];
	res += b[1];
	printf("%d", res);
}