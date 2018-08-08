#include <iostream>
#include <string.h>

int cache[1001], num[1001];
int v[1001];
int n;
int Lis(int);
int max(int a, int b) {
	return a > b ? a : b;
}

void print(int i) {
	if (v[i] == 0) {
		printf("%d", num[i]);
		return;
	}
	printf("%d ", num[i]);
	print(v[i]);
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	int res = 0;
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		tmp = Lis(i);
		if (res < tmp) {
			res = tmp;
		}
	}
	printf("%d\n", res);
	int i;
	for (i = 0; i < n; ++i)
		if (cache[i] == res)
			break;
	print(i);
}

int Lis(int start) {
	int& ref = cache[start];
	int itmp = 0;
	if (start >= n)
		return 0;
	else if (ref != -1)
		return ref;
	else {
		ref = 1;
		for (int i = start + 1; i < n; ++i) {
			if (num[start] < num[i]) {
				itmp = Lis(i) + 1;
				if (ref < itmp) {
					ref = itmp;
					v[start] = i;
				}
			}
		}
		return ref;
	}
}