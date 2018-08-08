#include<cstdio>

int main() {
	int a, b, c;
	int pow2[15] = { 1 };
	for (int i = 1; i < 15; ++i)
		pow2[i] = pow2[i - 1] * 2;
	scanf("%d %d %d", &a, &b, &c);

	if (b*b - 4 * a*c <= 0)
		printf("둘다틀렸근");
	else {
		int ans1 = -100000000;
		int ans2 = ans1;
		for (int i = -100; i <= 100; ++i) {
			if (a*i*i + b * i + c == 0) {
				if (ans1 < -1000000)
					ans1 = i;
				else {
					ans2 = i;
					break;
				}
			}
		}
		if (ans1 < -1000000 || ans2 < -1000000)
			printf("둘다틀렸근");
		bool chk[2] = { 0 };
		for (int i = 0; i < 15; ++i) {
			if (ans1 == pow2[i])
				chk[0] = 1;
			if (ans2 == pow2[i])
				chk[1] = 1;
		}
		if (chk[0] && chk[1])
			printf("이수근");
		else
			printf("정수근");
	}
}