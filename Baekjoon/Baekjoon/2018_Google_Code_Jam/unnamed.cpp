#include <iostream>
#include <algorithm>

using namespace std;

enum {X, Y};

bool cake[102][102];	//1 chocolate, 0 empty	[0][0] = NULL
int r, c, h, v;

int CntChocolate(int sx, int sy, int ex, int ey) {
	int res = 0;
	for (int i = sy; i <= ey; ++i) {
		for (int j = sx; j <= ex; ++j) {
			if (cake[i][j])
				++res;
		}
	}
	return res;
}

bool check(int mx, int my) {
	if (mx < 0 || my < 0 || mx > c - 2 || my > r - 2)
		return 0;
	else {
		int A, B, C, D;
		A = CntChocolate(0, 0, mx, my);
		B = CntChocolate(mx + 1, 0, c - 1, my);
		C = CntChocolate(0, my + 1, mx, r - 1);
		D = CntChocolate(mx + 1, my + 1, c - 1, r - 1);
		if (A == B && B == C && C == D)
			return 1;
		else
			return 0;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		scanf("%d %d %d %d", &r, &c, &h, &v);	//@ chocolate, . empty

		char msg[101];
		int cntCh = 0;
		int cntPiece = (h + 1)*(v + 1);
		for (int i = 0; i < r; ++i) {
			scanf("%s", msg);
			int j = 0;
			while (msg[j] != '\0') {
				if (msg[j] == '@') {
					cake[i][j] = 1;
					cntCh++;
				}
				else
					cake[i][j] = 0;
				++j;
			}
		}


		//output
		printf("Case #%d: ", tt);
		if (cntCh % cntPiece != 0)
			printf("IMPOSSIBLE");
		else {
			bool checker = 0;
			for (int i = 0; i < r - 1; ++i) {
				for (int j = 0; j < c - 1; ++j) {
					if (check(j, i)) {
						checker = 1;
						break;
					}
				}
				if (checker)
					break;
			}
			if (checker)
				printf("POSSIBLE");
			else
				printf("IMPOSSIBLE");
		}
		printf("\n");
	}
}