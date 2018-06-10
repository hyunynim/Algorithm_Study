#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int l, r, a;
	scanf("%d %d %d", &l, &r, &a);
	while (l != r && a>0) {
		if (l > r)++r;
		else if (l < r) ++l;
		--a;
		if (l == r)
			break;
	}
	if (a)
		printf("%d", min(l, r) * 2 + (a - a%2));
	else
		printf("%d", min(l, r) * 2);
}