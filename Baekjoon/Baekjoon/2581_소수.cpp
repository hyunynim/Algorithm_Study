#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	vector <int> primeNum;
	int m, n;
	scanf("%d %d", &m, &n);
	int cntPrime = 0, sum = 0, min = 10000, v_sqrt = 0;
	int div, isPrime = 1;
	for (int i = m; i <= n; i++) {
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
			sum += i;
		}
	}
	if (primeNum.size() == 0) {
		printf("-1");
		return 0;
	}
	printf("%d\n", sum);
	printf("%d", primeNum[0]);
}