#include<cstdio>
#include<algorithm>
using namespace std;
bool chk[12];
int ABS(int a) {
	return a > 0 ? a : -a;
}

int check(int a) {
	if (a) {
		int cnt = 0;
		while (a > 0) {
			if (chk[a % 10])
				return 0;
			++cnt;
			a /= 10;
		}
		return cnt;
	}
	else {
		return !chk[0];
	}
}

int main() {
	int n, tmp;
	scanf("%d", &n);
	int ans = ABS(n - 100);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &tmp);
		chk[tmp] = 1;
	}
	for (int i = 0; i <= 1000000; ++i) {
		int len = check(i);
		if (len) 
			ans = min(ans, len + ABS(i - n));
	}
	printf("%d", ans);
}