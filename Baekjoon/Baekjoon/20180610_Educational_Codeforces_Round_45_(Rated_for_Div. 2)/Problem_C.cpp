#include<iostream>
#include<stack>
#include<algorithm>

#define pb(x) push_back(x)

using namespace std;
long long cnt[2][300001] = { 0 }; //0:( 1:) �Ұ����� üũ ����
char msg[300000];
stack<char> chk;
int main() {
	int n;
	long long cntC = 0;
	long long res = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int stat = 0;
		int tmp = 0;
		cin >> msg;
		while (chk.size())
			chk.pop();
		for (int j = 0; msg[j] != '\0'; ++j) {
			if (msg[j] == '(')
				chk.push('(');
			else {
				if (chk.size()) 
					chk.pop();
				else 
					++tmp;
			}
		}
		if (chk.empty()) {
			if (tmp)
				++cnt[1][tmp];
			else
				++cntC;
		}
		else {
			if (tmp)
				continue;
			cnt[0][chk.size()]++;
		}
	}
	for (int i = 1; i < 300001; ++i) {
		if (cnt[0][i])
			res += cnt[0][i] * cnt[1][i];
	}
	res += cntC * cntC;
	cout << res;
}

/*comment*/
//���� ��ȣ�� )( ���·� �̷���� ������ ���ʿ� ����
//���°�ȣ�� �ѹ��� ((( �Ǵ� ))) ���̸� �ش� �������� ¦���缭 �����ָ�ɵ�
//)()()( �̷� case�� ���� ����
//tmp == 300000 �� ��� �迭�� ���� ���� �� ����. �迭 ������ ����
//���� Ʋ���� �� �𸣰���
//���ϱ⿡�� overflow �߻� ����
//�ذ�