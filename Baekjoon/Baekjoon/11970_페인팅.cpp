#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (b <= c || d <= a)
		printf("%d", b-a + d - c);
	else
		printf("%d", max(b, d) - min(a, c));
}

/*comment*/
//겹치는 구간 없을 때 처리