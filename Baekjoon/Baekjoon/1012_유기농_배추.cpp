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
//�� Ʋ������....
//�� ���� ��� üũ�ϰ� �ٲ������ Ʋ��
//���߰� ��� isChecked üũ�ϰ� �Ѿ�Բ� �ٲ�
//���߰� ������� �� ���� Ȯ�� ���ϰ� �ٷ� �Ѿ
//Ʋ��
//field�� y�� x�� �ݴ�� ���� -> �ǳ� �ϴ� �Ǽ� -_-