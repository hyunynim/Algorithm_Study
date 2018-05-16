#include<cstdio>
#include<algorithm>
using namespace std;


int PushbackReverse(int a) {
	int b = 0;
	while (a > 0) {
		b = b * 10 + a % 10;
		a /= 10;
	}
	return b;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int max = 0, tmp;
	for (int i = 1; i <= k; ++i) {
		tmp = PushbackReverse(n*i);
		if (tmp > max)
			max = tmp;
	}
	printf("%d", max);
		
}