#include<cstdio>
#include<algorithm>
using namespace std;

int seq[1234];
int res[2][1234];
int n;

int LDS(int num) {
	if (num >= n)
		return 0;
	else {
		int & ans = res[1][num];
		if (ans != 0)
			return ans;
		ans = 1;
		for (int i = num + 1; i < n; ++i) {
			if (seq[num] > seq[i]) {
				int tmp = LDS(i) + 1;
				if (ans < tmp) {
					ans = tmp;
				}
			}
		}
		return ans;
	}
}

int LIS(int num) {
	if (num >= n)
		return 0;
	else{
		int & ans = res[0][num];
		if (ans != 0)
			return ans;
		ans = 1;
		for (int i = num + 1; i < n; ++i) {
			if (seq[num] < seq[i]) {
				ans = max(ans, LIS(i) + 1);
				ans = max(ans, LDS(i) + 1);
			}
		}
		return ans;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, LIS(i));
	}
	printf("%d", ans);
}