#include<cstdio>

int main() {
	int a, d, k, res;
	scanf("%d %d %d", &a, &d, &k);
	res = (k - a) / d + 1;
	if ((k - a) % d != 0 || res <= 0)
		printf("X");
	else
		printf("%d", res);
}
/*comment*/
//������ 0�ΰ�� -> ������ �ʿ� ������
//�׹�ȣ�� ������ �����°�� -> �������� �ʴ� ���̽� �̹Ƿ� ���� ������