#include <stdio.h>
#include <string.h>

bool field[50][50];
bool isChecked[50][50];
int w, h;
bool CheckField(int x, int y) {
	if (x < 0 || y < 0 || x >= w || y >= h)
		return 0;
	if (isChecked[y][x])
		return 0;
	else {
		isChecked[y][x] = 1;
		if (field[y][x]) {
			CheckField(x + 1, y);
			CheckField(x - 1, y);
			CheckField(x, y + 1);
			CheckField(x, y - 1);
		}
		else
		{
			isChecked[y][x];
				return 0;
		}
	}
	return 1;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		memset(field, 0, sizeof(field));
		memset(isChecked, 0, sizeof(isChecked));
		int k, x, y, res = 0;
		scanf("%d %d %d", &w, &h, &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d %d", &x, &y);
			field[y][x] = 1;
		}

		for (int yNext = 0; yNext < h; ++yNext) {
			for (int xNext = 0; xNext < w; ++xNext) {
				if (CheckField(xNext, yNext))
					res++;
			}
		}
		printf("%d\n", res);
	}
}

/*comment*/
//왜 틀렸을까....
//네 방향 모두 체크하게 바꿔봤지만 틀림
//배추가 없어도 isChecked 체크하고 넘어가게끔 바꿈
//배추가 없을경우 네 방향 확인 안하고 바로 넘어감
//틀림
//field의 y와 x를 반대로 썼음 -> 맨날 하는 실수 -_-