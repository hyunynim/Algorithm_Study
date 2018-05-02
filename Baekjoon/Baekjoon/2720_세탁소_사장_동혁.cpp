#include <iostream>

void calc(int c, int*ans);

int main() {
	int t;
	int c;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int ans[4] = { 0 };
		scanf("%d", &c);
		calc(c, ans);
		for (int j = 0; j < 4; j++)
			printf("%d ", ans[j]);
		printf("\n");
	}
}

void calc(int c, int*ans) {
	ans[0] = c / 25;
	c %= 25;
	ans[1] = c / 10;
	c %= 10;
	ans[2] = c / 5;
	c %= 5;
	ans[3] = c;
}