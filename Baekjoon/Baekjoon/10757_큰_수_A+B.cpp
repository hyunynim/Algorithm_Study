#include <iostream>
#include <string.h>
#include <stack>
#define MAX_STRING_LENGTH 10002

using namespace std;

int main() {
	char a[MAX_STRING_LENGTH], b[MAX_STRING_LENGTH];
	stack <char> num1, num2, num3;
	scanf("%s %s", a, b);
	int i, j, tmp;
	int chkNextDegree = 0;

	for (i = 0; a[i] != '\0'; i++)
		num1.push(a[i] - '0');

	for (j = 0; b[j] != '\0'; j++)
		num2.push(b[j] - '0');

	while (i && j) {
		tmp = 0;
		if (i != 0)
			tmp += num1.top();
		if (j != 0)
			tmp += num2.top();
		if (chkNextDegree == 1)
			tmp += 1;

		if (num1.top() + num2.top() + chkNextDegree >= 10)
			chkNextDegree = 1;
		else
			chkNextDegree = 0;

		tmp %= 10;
		num3.push(tmp);
		
		if (i != 0)
			num1.pop();
		if (j != 0)
			num2.pop();
		i--;
		j--;
	}
	while (num1.size()) {
		num3.push((num1.top() + chkNextDegree)%10);
		chkNextDegree = num1.top() = (num1.top() + chkNextDegree) / 10;
		num1.pop();
	}
	while (num2.size()) {
		num3.push((num2.top() + chkNextDegree) % 10);
		chkNextDegree = num2.top() = (num2.top() + chkNextDegree) / 10;
		num2.pop();
	}
	if (chkNextDegree == 1)
		num3.push(1);
	while (num3.size()) {
		printf("%d", num3.top());
		num3.pop();
	}
}

/*comment*/
//vector ���� stack���� ����
//���ƾ��� string���� «
//�޸��ʰ� �ᱹ ����
//Str2Int�� ���ļ� �ڿ������� �ǰԲ� �ؾ� �� ��;
//����ʰ� ??
//Ʋ�Ƚ��ϴ� -> �տ� 0������ ���̽��� ����
//Ʋ�Ƚ��ϴ�
//���ƾ���
//�ٽ� ���ƾ���
//���ڿ��� ����ϰ�
//�迭 ������ ������ Ʋ���ſ���;;;