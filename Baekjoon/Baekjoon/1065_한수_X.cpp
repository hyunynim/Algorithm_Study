#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int digit[4] = { 0, 0, 0, 0 };
	int ans = 99;
	int tmp;
	if (n < 100) {
		printf("%d", n);
		return 0;
	}
	else if(n < 111){
		printf("99");
		return 0;
	}
	else if (n == 111) {
		printf("100");
		return 0;
	}
	else {
		ans = 100;
		for (int i = 112; i <= n; i++) {
			tmp = i;
			for (int j = 0; i < 3; j++) {
				digit[2-i] = tmp % 10;
				tmp /= 10;
				printf("%d ", digit[i]);
			}
			if (digit[0] - digit[1] == digit[1] - digit[2])
				ans++;
		}
		printf("%d", ans);
	}
}