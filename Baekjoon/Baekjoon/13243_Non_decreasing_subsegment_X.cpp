#include<cstdio>
#include<string.h>
#include<vector>

int cache[1001], num[1001];

using namespace std;

int n;
int Lis(int);
long long maxRes = 0;
vector<int> vRes;
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	int res = 0, tmp;
	for (int i = 0; i < n; ++i) {
		tmp = Lis(i);
		if (tmp > res) {
			res = tmp;
		}
	}
	printf("%d %d", res, maxRes);
}

int Lis(int start) {
	int& ref = cache[start];
	if (start >= n)
		return 0;
	else if (ref != -1)
		return ref;
	else {
		ref = 1;
		int tmp, tmpIndex = 0;
		for (int i = start + 1; i < n; ++i) {
			if (num[start] <= num[i]) {
				tmp = Lis(i) + 1;
				if(tmp > ref){
					ref = tmp;
				}
			}
		}
		return ref;
	}
}

//어디에 합을 저장할지