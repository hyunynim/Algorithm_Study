#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool notPrime[1000002];
vector<int> prime;
int main() {
	notPrime[2] = 1;
	for (int i = 2; i <= 1000000; ++i) {
		if (notPrime[i])continue;
		if (i % 2)prime.push_back(i);
		for (int j = i + i; j <= 1000000; j += i) {
			notPrime[j] = 1;
		}
	}
	while (1) {
		int n;
		scanf("%d", &n);
		if (!n)break;
		int up = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
		for (int i = 0; i <= up; ++i) {
			if (binary_search(prime.begin(), prime.end(), n - prime[i])) {
				printf("%d = %d + %d\n",n,prime[i],*lower_bound(prime.begin(),prime.end(),n-prime[i]));
					break;
			}
		}
	}
}

//시간초과