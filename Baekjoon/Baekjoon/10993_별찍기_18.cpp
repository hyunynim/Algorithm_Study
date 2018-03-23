#include <stdio.h>

bool star[2050][2050] = { 0 };
int power(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2 != 0)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}
//(3, 2, 2, 0)
void print_star(int xi, int yi, int size, bool isTopDown) {
	if (size == 1) {
		star[xi][yi] = 1;
	}
	else if (size < 1) {}
	else {
		star[xi][yi] = 1;
		for (int i = 1; i <= power(2, size) - 2; i++) {
			if (isTopDown) {
				star[xi - i][yi + i] = 1;
				star[xi + i][yi + i] = 1;
				star[xi - i][yi + power(2, size)-2] = 1;
				star[xi + i][yi + power(2, size)-2] = 1;
			}
			else {
				star[xi - i][yi - i] = 1;
				star[xi + i][yi - i] = 1;
				star[xi - i][yi - power(2, size)+2] = 1;
				star[xi + i][yi - power(2, size)+2] = 1;
			}
		}
		print_star(xi, yi - (isTopDown ?-( power(2, size) - 3) : power(2, size) - 3), size - 1, !isTopDown);
		star[xi][yi - (isTopDown ? -(power(2, size) - 2) : power(2, size) - 2)] = 1;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	print_star(power(2, n)-1, (n%2 == 0 ? power(2, n)-2:0), n, (n%2 == 0 ? 0 : 1));
	if (n % 2 == 0) {
		for (int i = 0; i < power(2, n) - 1; i++) {
			for (int j = 1; j <= power(2, n+1)-3 - i; j++) {
				if (star[j][i] == 0)
					printf(" ");
				else
					printf("*");
			}
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < power(2, n)-1; i++) {
			for (int j = 1; j <= power(2, n)-1 + i; j++) {
				if (star[j][i] == 0)
					printf(" ");
				else
					printf("*");
			}
			printf("\n");
		}
	}
}


//밑변 a_(n) = a_(n-1) + 2^n
//밑변 2^(n+1) - 3개
//양변 2^(n+1) - 3개 (각, 2^n - 1개)
//별출력 안됨
//출력형식 잘못됨 -> 오른쪽 공백 없애기
//정답