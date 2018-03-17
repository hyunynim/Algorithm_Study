#include <stdio.h>
#include <math.h>

int main() {
	int m, n;
	int v_sqrt, chkPrime;
	scanf("%d %d", &m, &n);
	if (m == n && m == 1)
		return 0;
	while (m <= n) {
		if (m == 1)
			m = 2;
		chkPrime = 1;
		v_sqrt = (int)sqrt((double)m);
		if (m % 2 == 0 && m != 2) {
			++m;
			continue;
		}
		else if (m == 2) {
			printf("2\n");
			++m;
			continue;
		}
		else {
			for (int i = 3; i <= v_sqrt; i += 2) {
				if (m%i == 0) {
					chkPrime = 0;
					break;
				}
			}
			if (chkPrime == 1)
				printf("%d\n", m);
		}
		++m;
	}
}

/*comment*/
//	1을 고려하지 않아서 틀림
