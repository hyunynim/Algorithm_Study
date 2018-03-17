#include <stdio.h>

int chk_incredible(int n) {
	int res[3];
	int tmp = n;
	while (tmp > 0) {
		res[0] += tmp % 10;
		tmp /= 10;
	}
	tmp = n;
	while (tmp > 0) {
		res[1] += tmp % 16;
		tmp /= 16;
	}
	tmp = n;
	while (tmp > 0) {
		res[2] += tmp % 12;
		tmp /= 12;
	}
	if (res[0] == res[1] && res[0] == res[2])
		return 1;
	return 0;
}

int main() {
	int start = 1000;
	while (start < 10000) {
		if (chk_incredible(start) == 1)
			printf("%d\n", start);
		start++;
	}
}