#include <iostream>
#define MAX(X, Y) X > Y ? X : Y
#define MIN(X, Y) X < Y ? X : Y

int gcd(int a, int b);
int lcm(int a, int b, int gcd);

int main() {
	int M, N, x, y, t;
	int ans = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		//calc
		if (M == N) {
			if (x == y)
				printf("%d", x);
			else
				printf("-1");
		}
		else if (x == y) {
			if (x <= M && y <= N)
				printf("%d", x);
			else
				printf("-1");
		}
		else {
			int v_lcm = lcm(M, N, gcd(MIN(M, N), MAX(M, N)));
			int calc, chk = 0;
			if (M > N)
			{
				calc = N + y;
				while (calc <= v_lcm) {
					if ((calc % M == 0 && M == x) || (calc % M == x)) {
						chk = 1;
						break;
					}
					calc += N;
				}
			}
			else
			{
				calc = M + x;
				while (calc <= v_lcm) {
					if ((calc % N == 0 && N == y) || (calc % N == y)) {
						chk = 1;
						break;
					}
					calc += M;
				}
			}
			if (chk == 1)
				printf("%d", calc);
			else
				printf("-1");
			}
		printf("\n");
		}
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b, int gcd) {
	return (a / gcd)*(b / gcd)*gcd;
}