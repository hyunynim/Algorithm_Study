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
//vector 말고 stack으로 구현
//갈아엎고 string으로 짬
//메모리초과 결국 원점
//Str2Int를 고쳐서 뒤에서부터 되게끔 해야 할 듯;
//출력초과 ??
//틀렸습니다 -> 앞에 0나오는 케이스가 있음
//틀렸습니다
//갈아엎어
//다시 갈아엎음
//문자열로 쎄깐하게
//배열 사이즈 때문에 틀린거였음;;;