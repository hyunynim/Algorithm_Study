#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;
int cache[1000010];

int makeIt(int n) {
	if (n <= 2)
		return n - 1;
	else {
		int & ans = cache[n];
		if (ans != -1)
			return ans;
		else {
			int res = 987654321;
			if (n % 3 == 0)
				res = min(res, makeIt(n / 3) + 1);
			if (n % 2 == 0)
				res = min(res, makeIt(n / 2) + 1);
			res = min(res, makeIt(n - 1) + 1);
			ans = res;
		}
		return ans;
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	cache[1] = 0;
	cache[2] = 1;
	int n;
	scanf("%d", &n);
	makeIt(n);
	printf("%d", cache[n]);
}