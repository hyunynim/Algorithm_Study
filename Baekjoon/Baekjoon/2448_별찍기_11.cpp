#include <stdio.h>
#include <math.h>

bool star[6200][3100] = { 0 };

void print_it(int x, int y, int flag) {
	if (flag == 0)
		star[x][y] = 1;
}

int pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2 != 0) {
			res *= a;
		}
		a *= a;
		n /= 2;
	}
	return res;
}

void print_star_3(int xi, int yi, int size) {
	print_it(xi, yi, 0);
	print_it(xi - 1, yi + 1, 0);	print_it(xi + 1, yi + 1, 0);
	for (int i = 0; i < 5; i++)
		print_it(xi - 2 + i, yi + 2, 0);

	if (size != 0) {
		print_star_3(xi, yi, size - 1);
		print_star_3(xi - 3 * pow(2, size - 1), yi + 3 * pow(2, size - 1), size - 1);
		print_star_3(xi + 3 * pow(2, size - 1), yi + 3 * pow(2, size - 1), size - 1);
	}
}

int main() {
	int n, size;
	scanf("%d", &n);
	size = log2(n / 3);
	print_it(n, 0, 0);
	print_star_3(n, 0, size);
	for (int i = 0; i < n; i++) {
		for (int k = 1; k <= 2*n-1; k++) {
			if (star[k][i] == 0) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}

/*comment*/
//n-1��° ���ο��� �� 2n-1���� ����� ���� ���
//n%3 == 0�� ������ *
//n%3 == 1�� ������ * *
//n%3 == 2�� ������ *****, ���̻��̿� ����		OK
//���ƾ���
//����Լ�
//1��° ȣ��� �κ� ��� �ȵ�
//gotoxy ��ٰ� ���ƾ���
//bool�̿�
//ū������ ���� ����� �ʹ� ���� �� �� �ڿ� ������ ����
//���ݴµ��� ��� �߸��ƴٰ� ����
//�� �ڿ� �����ŭ ������ ä���־�� ����
//�¾ҽ��ϴ�.