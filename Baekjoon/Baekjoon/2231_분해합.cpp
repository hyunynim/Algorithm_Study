#include<cstdio>

int calc(int n) {
	int res = n;
	while (n > 0) {
		res += (n % 10);
		n /= 10;
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	int tmp = 0;
	for (int i = 1; tmp < 1010101; ++i) {
		tmp = calc(i);
		if (tmp == n) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");

}
/*comment*/
//범위를 넓히니까 맞음