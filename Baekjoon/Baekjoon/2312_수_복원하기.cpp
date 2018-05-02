#include <iostream>
#include <vector>

using namespace std;

int getPrime(vector <int> & prime, int p);

int main() {
	int t;
	vector <int> prime;
	prime.push_back(2);
	prime.push_back(3);
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int num;
		scanf("%d", &num);
		int j = 0;
		while (num > 1) {
			if (num % prime[j] == 0) {
				printf("%d ", prime[j]);
				int cnt = 0;
				while (num % prime[j] == 0) {
					num /= prime[j];
					cnt++;
				}
				printf("%d\n", cnt);
			}
			++j;
			if (prime.size() == j)
				getPrime(prime, prime[j-1]);
		}

	}
}

int getPrime(vector <int> & prime, int p) {
	if (p == 2)
		return 3;
	else {
		for (int i = p + 2; ; i += 2) {
			bool isPrime = 1;
			for (int j = 0; j < prime.size(); ++j) {
				if (i%prime[j] == 0) {
					isPrime = 0;
					break;
				}
			}
			if (isPrime == 1) {
				prime.push_back(i);
				return i;
			}
		}
	}
}