#include <iostream>

int main() {
	int player[2] = { 100, 100 };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b)
			player[1] -= a;
		else if (a < b)
			player[0] -= b;
		else;
	}
	printf("%d\n%d", player[0], player[1]);
}