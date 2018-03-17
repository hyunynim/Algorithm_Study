#include <stdio.h>

int digital_root(int n) {
	int res = 0;
	if (n < 10)
		return n;
	else {
		while (n > 0) {
			res += n % 10;
			n /= 10;
		}
		return res;
	}
}

int main() {
	char msg[1001];
	int res = 0;
	while (msg[0] != '0') {
		res = 0;
		scanf("%s", msg);
		if (msg[0] == '0')
			break;
		for (int i = 0; msg[i] != '\0'; i++)
			res += msg[i] - 48;
		while (res > 9) {
			res = digital_root(res);
		}
		printf("%d\n", res);
	}
}

/*comment*/
//Recursion -> loop로 변경
//msg[0] == 0일 경우 끊어줘야함