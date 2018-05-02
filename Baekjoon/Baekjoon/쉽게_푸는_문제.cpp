#include <stdio.h>

int main() {
	int s, e;
	scanf("%d %d", &s, &e);
	int cnt = 1;
	int res = 0;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (s <= cnt && cnt <= e) {
				res += i;
			}
			cnt++;
		}
		if (cnt > e)
			break;
	}
	printf("%d", res);
}