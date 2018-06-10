#include<cstdio>

int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0)
			return 0;
		int res = 0, cnt = 0;
		while (n > 0) {
			switch (n % 10) {
			case 1:
				res += 2;
				break;
			case 0:
				res += 4;
				break;
			default:
				res += 3;
				break;
			}
			n /= 10;
			cnt++;
		}
		printf("%d\n", res + 1 + cnt);
	}
}