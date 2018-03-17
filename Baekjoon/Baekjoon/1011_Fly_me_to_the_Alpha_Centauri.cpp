#include <stdio.h>
#include <math.h>

int main() {
	unsigned int  x, y, t;
	unsigned int length, calc, ans, v_sqrt;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d %d", &x, &y);
		length = y - x;
		calc = 0;
		v_sqrt = (int)sqrt(length);
		if (v_sqrt*v_sqrt == length || v_sqrt > 10)
			v_sqrt--;
		while (1) {
			if ((v_sqrt - 1)*(v_sqrt - 1) < length && length <= (v_sqrt)*(v_sqrt + 1)) {
				ans = 2 * v_sqrt;
				break;
			}
			if ((v_sqrt)*(v_sqrt + 1) < length && length <= (v_sqrt+1)*(v_sqrt+1))
			{
				ans = 2 * v_sqrt + 1;
				break;
			}
			v_sqrt++;
		}
		printf("%d\n", ans);
	}
}

/*comment*/
// Test case�� ��� ���Ͽ� Ʋ��
// ���๮�ڰ� ������ Ʋ��
// ���� �ϳ��� ����ϰ� ������ Ʋ��
// ���ƾ���
// �ӵ��� ���������� �ð��ʰ�

// ���ƾ���
// a_(2n+1) = a_(2n-1) + (2n+1) // a_(2n+1) = n^2		a_(2n)+1 ~ a_(2n+1)�� ������ 2n+1
// a_(2n) = a_(2n-2) + 2n // a_(2n) = n(n+1)			a_(2n-1)+1 ~ a_(2n)�� ������ 2n
// �ð��ʰ�
// length = 2^31 �϶� overflow�� ������� ����
// ����