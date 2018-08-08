#include<cstdio>
#include<vector>

using namespace std;

bool sieve[4000000] = { 1,1 }; //0:prime

int main() {
	for (int i = 0; i * i < 4000000; ++i) {
		if (!sieve[i])
			for (int j = i * i; j < 4000000; j += i)
				sieve[j] = 1;
	}
	vector<int> prime;
	for (int i = 0; i < 4000000; ++i)
		if (!sieve[i])
			prime.push_back(i);
	int n, ans = 0;
	scanf("%d", &n);
	int l = 0, r = 0;
	vector<int> sum;
	for (int i = 0; i < prime.size(); ++i) 
		sum.push_back(sum.empty() ? prime[i] : prime[i] + sum.back());
	
	while (l <= r && r < prime.size()) {
		int res = sum[r] - (l ? sum[l - 1] : 0);
		if (res == n) {
			++ans;
			++r;
		}
		else if (res > n)
			++l;
		else
			++r;
		if (l > r || prime[l] > n)
			break;
	}
	printf("%d", ans);
}