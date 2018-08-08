#include<cstdio>
#include<vector>

using namespace std;

bool sieve[1234567] = { 1,1 }; //0:prime

bool isPel(int num) {
	int tmp = num, ans = 0;
	while (tmp > 0) {
		ans = ans * 10 + tmp % 10; tmp /= 10;
	}
	return num == ans;
}

int main() {
	for (int i = 0; i * i < 1234567; ++i) {
		if(!sieve[i])
			for (int j = i*i; j < 1234567; j += i)
				sieve[j] = 1;
	}
	vector<int> prime;
	for (int i = 0; i < 1234567; ++i)
		if (!sieve[i])
			prime.push_back(i);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < prime.size(); ++i) {
		if (prime[i] >= n && isPel(prime[i])) {
			printf("%d", prime[i]); return 0;
		}
	}
}