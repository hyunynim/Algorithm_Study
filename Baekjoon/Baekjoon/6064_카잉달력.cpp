#include <iostream>

int main() {
	int M, N, x, y, t;
	int ans = 0;
	int i, j;
	scanf("%d", &t);

	for (int k = 0; k < t; ++k) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		if (M == N) {
			if (x == y)
				printf("%d\n", x);
			else
				printf("-1\n");
		};
		
	}
}