#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> sz(n);
	for (int i = 0; i < n; ++i) {
		cin >> sz[i];
	}
	sort(sz.begin(), sz.end());

	vector<int>::iterator it = sz.begin();
	int res = 0;
	int sizeOffset = sz[0] + k, tmp = 1;
	for (int i = 1; i < sz.size(); ++i) {
		if (sz[i - 1] < sz[i] && sizeOffset >= sz[i]) {
			res += tmp;
			tmp = 1;
		}
		else if (sz[i - 1] == sz[i])
			++tmp;
		else
			tmp = 1;
		sizeOffset = sz[i] + k;
	}
	printf("%d", sz.size() - res);
}

/*comment*/
//�� �����Ű�� ������� �ߴµ� �ּڰ��� ������ �ȵǴ°ǰ�
//��Ʋ���°��� �� �𸣰���
//�� ���׸��� ����� ������ check ����
//����� ���ٰ� ���԰� �Ѿ���� tmp �ʱ�ȭ ������