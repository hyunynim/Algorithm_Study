#include <stdio.h>
bool mine[750][750] = { 0 };
int r, c;

enum { X, Y };
int DiamondMine(int size, int *start, int *end) {
	if (size == 0 || start[X] < 0 || start[Y] < 0 || end[X] >= c || end[Y] >= r)
		return 0;
	for (int i = start[Y]; i <= end[Y]; ++i) {
		for (int j = start[X]; j <= end[X]; ++j) {
			int k = 0;
			bool isEnd = 0;
			while (k < size) {
				if (mine[i - k][j - (size - 1) + k] && mine[i + k][j - (size - 1) + k] && mine[i - k][j + (size - 1) - k] && mine[i + k][j + (size - 1) - k]);
				else {
					isEnd = 1;
					break;
				}
				k++;
			}
			if (!isEnd)
				return size;
		}
	}
	start[X]--;
	start[Y]--;
	end[X]++;
	end[Y]++;
	DiamondMine(size - 1, start, end);
}

int main() {
	bool cnt_one = 0, isContinue = 1;
	int maxSize;
	scanf("%d %d", &r, &c);

	int start[2];
	int end[2];

	r < c ? (r % 2 == 0 ? maxSize = r / 2 : maxSize = (r + 1) / 2) : (c % 2 == 0 ? maxSize = c / 2 : maxSize = (c + 1) / 2);
	start[X] = maxSize - 1;
	start[Y] = maxSize - 1;
	end[X] = c - maxSize;
	end[Y] = r - maxSize;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%1d", &mine[i][j]);
			if (cnt_one == 0 && mine[i][j] == 1)
				cnt_one = 1;
		}
	}
	if (cnt_one == 0) {
		printf("0");
		return 0;
	}
	else {
		printf("%d", DiamondMine(maxSize, start, end));
	}
}

/*comment*/
//start, end pos �߸� ����
//�� Ʋ��
//Ȥ�� X, Y�� �ݴ�ν質..
//�ݴ�� ���� �´µ� �ѵ� �� Ʋ��...
//while���� k < size -1 -> k < size  Ƚ�� �߸������Ǿ�����
//�ٵ� ��Ʋ��
//1¥�� case�� ����Ƴ�
//end pos�� �� �߸� �����س��� X Y �ٲ㼭
//�¾Ҵپ�..��..