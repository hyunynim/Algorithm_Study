#include <stdio.h>

bool quad[64][64] = { 0 };

int CheckQuad(int sx, int ex, int sy, int ey) {
	bool tmp = quad[sy][sx];
	if (sx == ex && sy == ey)
		return tmp;
	for (int i = sy; i <= ey; ++i) {
		for (int j = sx; j <= ex; ++j) {
			if (tmp == quad[i][j]);
			else
				return -1;
		}
	}
	return tmp;
}

void Quad(int sx, int ex, int sy, int ey) {
	int midX = (sx + ex) / 2;
	int midY = (sy + ey) / 2;
	int chkRes = CheckQuad(sx, ex, sy, ey);
	if (chkRes == -1) {
		printf("(");
		Quad(sx, midX, sy, midY);
		Quad(midX + 1, ex, sy, midY);
		Quad(sx, midX, midY + 1, ey);
		Quad(midX + 1, ex, midY + 1, ey);
		printf(")");
	}
	else {
		printf("%d", chkRes);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%1d", &quad[i][j]);
	}
	Quad(0, n-1, 0, n - 1);
}