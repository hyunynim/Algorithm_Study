#include <stdio.h>

void max(unsigned long long * a, unsigned long long *b) {
	unsigned long long tmp;
	if (*a > *b) {
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	unsigned long long a, b;
	scanf("%llu %llu", &a, &b);
	if(a == b) {
		for (int i = 0; i < a; i++)
			printf("1");
		return 0;
	}
	long long res = gcd(a, b);
	if (res == 1)
		printf("1");
	else {
		for (int i = 0; i < res; i++)
			printf("1");
	}

}

/*comment*/
//a == b�ϰ�� ��� ����
//?? ��Ʋ����
//gcd�� Ǯ����� �ߴµ� �׳� �������� 0�� �ƴҰ��� ǰ;;;;;