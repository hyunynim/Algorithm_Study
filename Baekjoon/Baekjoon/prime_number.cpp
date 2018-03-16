#include <stdio.h>

int prime_num[1000000] = { 2 };

int main()
{
	int sz = 1, j, chk = 0;
	for (j = 3; j <= 1000000; j++) {
		for (int i = 0; i < sz; i++) {
			if (j%prime_num[i] == 0) {
				chk++;
				break;
			}
		}
		if (chk == 0) {
			prime_num[sz] = j;
			sz++;
		}
		chk = 0;
	}
	/*
	for (int i = 0; i < sz; i++) {
		printf("%d\n", prime_num[i]);
	}
	*/
	return 0;
}