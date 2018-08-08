#include<cstdio>
#include<string.h>

int cache[1001], num[1001];

int n;
int Lds(int);
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
		res = max(res, Lds(i));
	}
	printf("%d", res);
}

int Lds(int start) {
	int& ref = cache[start];
	if (start >= n)
		return 0;
	else if (ref != -1)
		return ref;
	else {
		ref = 1;
		for (int i = start + 1; i < n; ++i) {
			if (num[start] > num[i])
				ref = max(ref, Lds(i) + 1);
		}
		return ref;
	}
}