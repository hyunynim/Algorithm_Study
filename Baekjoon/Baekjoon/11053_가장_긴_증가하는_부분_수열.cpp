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
	int& ref = cache[start];
	if (start >= n)
		return 0;
	else if(ref != -1)
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
//너무 단순구조로 생각해서 풀었음. 중간중간 뛰어넘는 경우를 생각 안함
//memoization에 정상적인 값 저장을 안함