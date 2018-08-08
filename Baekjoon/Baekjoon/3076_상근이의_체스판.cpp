#include<cstdio>

bool board[11][11][11][11];
int main() {
	int r, c, a, b;
	scanf("%d %d %d %d", &r, &c, &a, &b);

	for (int i = 0; i < r; ++i) {
		for (int k = 0; k < a; ++k) {
			for (int j = 0; j < c; ++j) {
				if (i % 2 == 0 && j % 2 == 0 || i % 2 && j % 2) {
					for (int l = 0; l < b; ++l)
						printf("X");
				}
				else {
					for (int l = 0; l < b; ++l)
						printf(".");
				}
			}
			puts("");
		}
	}
}