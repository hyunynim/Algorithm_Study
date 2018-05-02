#include <iostream>

int main() {
	int n;
	int res = 0;
	int oddCnt = 0;
	int min = 1000;
	for (int i = 0; i < 7; i++) {
		scanf("%d", &n);
		if (n % 2 == 1) {
			res += n;
			if (min > n)
				min = n;
			oddCnt++;
		}
	}
	if (oddCnt == 0)
		printf("-1");
	else {
		printf("%d\n%d", res, min);
	}
}