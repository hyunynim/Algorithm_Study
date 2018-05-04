#include <iostream>
#include <string.h>

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
	printf("%d", res);
}

int Lis(int start) {
	if (start >= n)
		return 0;
	int& ref = cache[start];
	if (ref != -1)
		return ref;
	else {
		ref = num[start];
		for (int i = start + 1; i < n; ++i) {
			if (num[start] < num[i])
				ref = max(ref, num[start] + Lis(i));
		}
		return ref;
	}
}

/*comment*/
//ref 초기식 잘못설정