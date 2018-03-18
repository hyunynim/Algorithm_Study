#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	vector <int> primeNum;
	int m, n;
	while (1) {
		scanf("%d", &m);
		if (m == 0)
			return 0;
		m = 2;
		n = 10000;
		int cntPrime = 0, sum = 0, min = 10000, v_sqrt = 0;
		int div, isPrime = 1;
		for (int i = m + 1; i <= n; i++) {
			if (i == 1)
				continue;
			v_sqrt = (int)sqrt((double)i);
			div = 2;
			isPrime = 1;
			while (div <= v_sqrt) {
				if (i%div == 0) {
					isPrime = 0;
					break;
				}
				if (div != 2)
					div += 2;
				else
					div++;
			}
			if (isPrime == 1) {
				primeNum.push_back(i);
				sum++;
			}
		}
		for (int i = 0; i < primeNum.size(); i++)
			printf("%d\n", primeNum[i]);
	}
}