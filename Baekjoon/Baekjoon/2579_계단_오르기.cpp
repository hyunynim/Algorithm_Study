#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int dp[305][2];
int a[305];
int rec(int x, int y)
{
	if (x == 0) {
		if (y == 1) return a[x];
		return 0;
	}
	if (x == 1 && y == 1) return a[x];
	int& ret = dp[x][y];
	if (ret)return ret;
	if (y) {
		ret = a[x] + max(rec(x - 2, 1), rec(x - 2, 0));
	}
	else {
		ret = a[x] + rec(x - 1, 1);
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i<n; ++i)scanf("%d", &a[i]);
	printf("%d",max(rec(n-1,0),rec(n-1,1)));
}
/*comment*/
//�� ���� Ʋ���� ���������� �𸣰���
//����Լ� ���ƾ���
//�ð��ʰ�
//�޸������̼� �����غ�
//Ʋ�� -> �ߺ� case�� �����µ�
//0 -> 2 �� 1 -> 2 �ϸ� �Ѵ� n==2 �� ���·� �����
//�ߺ�case ���� �ʿ�
//�ΰ� �Լ�, �ΰ� cache �̿�
//�ð��ʰ� 