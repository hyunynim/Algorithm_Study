#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, s, sum = 0;
	scanf("%d %d", &n, &s);
	int seq[123456];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		sum += seq[i];
	}
	if (s > sum) {
		printf("0"); return 0;
	}

	int left = 0, right = 0;

	int ans = (int)1e9;
	sum = seq[0];

	while (left < n && right < n) {
		if (s <= sum) {
			ans = min(ans, right - left + 1);
			sum -= seq[left];
			++left;
		}
		else {
			++right;
			if (right == n)
				break;
			sum += seq[right];
		}
	}
	printf("%d", ans);

}