#include <iostream>

int main() {
	int a, b, v, calc1, day=0;
	scanf("%d %d %d", &a, &b, &v);

	if (a - b == 1) {
		printf("%d", v - b);
		return 0;
	}

	while (v > a) {
		calc1 = v / a;
		v = v - (a*calc1) + (b*calc1);
		day += calc1;
	}

	printf("%d", day+1);
	return 0;
}

/*commnet*/
//�ð����⵵�� O(log N)�ε� �ð��ʰ� ��
//a-b == 1�� ��� ���� ���� ���
