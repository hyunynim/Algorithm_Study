#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, s, e, tmp;
	vector <int> num;
	vector <int> num_tmp;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s, &e);
		if (is_sorted(num.begin() + (s - 1), num.begin() + ((e - s) / 2))) {
			//�����̹Ƿ� �ڿ� �˻�
			for (int i = e - 1; num.begin() + i != num.begin() + ((e - s) / 2 - 1); --i) {
				if (num.begin() + i != num.begin() + (e - 1 - i) + (s - 1))
				{
					printf("0\n");
					break;
				}
			}
			printf("1\n");
		}
		else
			printf("0\n");
		num_tmp.clear();
	}
}

/*comment*/
//+1���� -1���� üũ�ؼ� Up, Down Ȯ���Ͽ� Ǯ������� �ð��ʰ�
//sorted �������� üũ�ؼ� Ǯ������� ����ε� ���� �ȳ���
//���ƾ���
