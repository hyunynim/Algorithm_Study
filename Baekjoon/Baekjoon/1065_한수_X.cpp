#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int digit[4] = { 0, 0, 0, 0 };
	int ans = 99;
	int tmp;
	if (n < 100) {
		printf("%d", n);
		return 0;
	}
	else if (n == 1000){
		printf("144");
	return 0;
	}
	else {
		ans = 99;
		for (int i = 100; i <= n; i++) {
			tmp = i;
			for (int j = 0; j < 3; j++) {
				digit[2-j] = tmp % 10;
				tmp /= 10;
			}
			if (digit[0] - digit[1] == digit[1] - digit[2])
				ans++;
		}
		printf("%d", ans);
	}
}

/*comment*/
//���� ���� �ö󰡺��� �ߴµ� ��������
//nasted for�� �ȿ� j�� �ƴ϶� i�� ��
//1000�϶� 000 �̱� ������ ���� ���� ����