#include<cstdio>
#include<string.h>

int cache[1001], num[1001];

int n;
int Lis(int);
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, Lis(i));
	}
	printf("%d", n - res);
}

int Lis(int start) {
	int& ref = cache[start];
	if (start >= n)
		return 0;
	else if (ref != -1)
		return ref;
	else {
		ref = 1;
		for (int i = start + 1; i < n; ++i) {
			if (num[start] < num[i])
				ref = max(ref, Lis(i) + 1);
		}
		return ref;
	}
}

/*comment*/
//항상 0부터 시작하는 경우에만 최대값을 구함 