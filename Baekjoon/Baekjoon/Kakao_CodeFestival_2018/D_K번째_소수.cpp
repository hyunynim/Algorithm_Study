#include<cstdio>
#include<vector>

using namespace std;

bool sieve[8000000] = { 1,1 }; //0:prime

int main() {
	for (int i = 0; i * i < 8000000; ++i) {
		if (!sieve[i])
			for (int j = i * i; j < 8000000; j += i)
				sieve[j] = 1;
	}
	vector<int> prime;
	for (int i = 0; i < 8000000; ++i)
		if (!sieve[i])
			prime.push_back(i);

	int n;
	scanf("%d", &n);
	printf("%d", prime[n - 1]);
}