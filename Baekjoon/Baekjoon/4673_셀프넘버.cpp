#include <stdio.h>
bool selfNum[10001] = { 0 };

int dn(int n) {
	selfNum[n] = 1;
	int res = n;
	if (n < 10)
		res += n;
	else {
		while (n > 0) {
			res += n % 10;
			n /= 10;
		}
	}
	return res;
}
int main()
{
	int n = 1;
	printf("1\n");
	while (1) {
		while (n <= 10000) {
			n = dn(n);
		}
		n = 1;
		while (selfNum[n] == 1)
			n++;
		if (n > 10000)
			break;
		printf("%d\n", n);
	}
}


/*comment*/
//Recursion func로 시도해봤지만 stack overflow
//출력초과