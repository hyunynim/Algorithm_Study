#include <iostream>

int main() {
	int r = 1, w, l;
	int cnt = 1;
	while (r != 0) {
		scanf("%d", &r);
		if (r == 0)
			break;
		scanf("%d %d", &w, &l);
		if (2 * r * 2 * r >= w * w + l * l)
			printf("Pizza %d fits on the table.\n", cnt);
		else
			printf("Pizza %d does not fit on the table.\n", cnt);
		cnt++;
	}

}

/*comment*/
//���ϴ� ��츦 ���� ����
//cnt++�� �ȳ���;;;
//ó���� �¾Ҵµ� cnt++�� �ȳ־ Ʋ��;;;;