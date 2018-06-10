#include<cstdio>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
	int n, tmp;
	scanf("%d", &n);
	deque<int> seq;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			seq.push_back(tmp);
		}
		if (i != 0) {
			sort(seq.begin(), seq.end());
			for (int j = 0; j < n; ++j)
				seq.pop_front();
		}
	}
	printf("%d", seq.front());
}

/*comment*/
//��¥ ��ư� �����ߴµ� �׳� �����̵� ������ ����� �����̶�� ���� �ɵ�