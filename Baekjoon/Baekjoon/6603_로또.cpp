#include <iostream>

int main() {
	int t = 1;
	int offset[6] = { 0, 0, 0, 0, 0, 0 };
	while (t != 0) {
		scanf("%d", &t);
		if (t == 0)
			continue;
		int * num = new int[t];
		
		for (int i = 0; i < t; i++) {
			scanf("%d", &num[i]);
			if(i < 6)
				offset[i] = 0;
		}
		while (t - offset[0] != 6) {
			for (int i = 0; i < 5; i++) {
				if (offset[5 - i] == t-5) {
					offset[5 - i - 1]++;
					if (offset[5 - i - 1] == t - 5)			//���⼭����
						continue;
					else {
						for (int j = 5 - i; j < 6; j++) {
							offset[j] = offset[5 - i - 1];
						}									//��������� ������ �¾��̵��
					}
				}
			}
			for (int i = 0; i < 6; i++) {
				printf("%d ", num[i + offset[i]]);
			}
			printf("\n");
			for (int i = 0; i < 5; i++) {
				if (offset[5 - i] == t - 5)
					continue;
				offset[5 - i]++;
				break;
			}
		}
		delete[] num;
		printf("\n");
	}
}

/*comment*/
//����� tC6��
//offset ���� �ٷ�Ⱑ �������