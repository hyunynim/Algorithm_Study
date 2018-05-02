#include <cstdio>

long long cache[32][32] = { {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1} };

int main() {
	for (int i = 5; i < 31; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || i == j)
				cache[i][j] = 1;
			else if (i - j == 1 || j == 1)
				cache[i][j] = i;
			else
			cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
		}
	}
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	if (n == 1 || m == 1) {
		printf("1");
		return 0;
	}
	if (k == 0) {
		printf("%lld", cache[n+m - 2][m - 1]);
	}
	else {
		int cnt = 1, i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (cnt == k)
					break;
				cnt++;
			}
			if (cnt == k)
				break;
		}
		--m; --n;
		printf("DEBUG :");
		printf("\ni: %d\n", i);
		printf("j: %d\n", j);
		printf("m: %d\n", m);
		printf("n: %d\n", n);
		printf("%lld", cache[n + m - i - j][m - j] * cache[i + j][i]);
	}
}
/*comment*/
//���ڰ� nxm�̸� ���� n-1�� m-1���� ���� ����
//�ƴ� ����ü ��� Ʋ������ �� �ٺ���
//�������� ������ �𼭸��� ������� ����� ���� ���ؼ� ����
//n�Ǵ� m�� 1�ΰ�� ���� ó��
//��Ʋ������ ������ ��ã����..
//�������� �Ƴ�
//���� ä��� �κп��� j==1�� case �߰�