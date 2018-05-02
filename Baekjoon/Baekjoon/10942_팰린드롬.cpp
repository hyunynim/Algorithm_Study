#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int isPel(vector <int> * num, int start, int end);
int cache[2001][2001];

int main() {
	int n, m, s, e, tmp;
	for (int i = 0; i < 2001; ++i) {
		for (int j = 0; j < 2001; ++j)
			cache[i][j] = -1;
	}
	vector <int> num;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	
	scanf("%d", &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &s, &e);
		s--; e--;
		if (isPel(&num, s, e))
			printf("1\n");
		else
			printf("0\n");
	}
	
}

int isPel(vector <int> * num, int start, int end) {
	if (cache[start][end] == -1) {
		if (start == end) {
			cache[start][end] = 1;
			return 1;
		}
		else if (end - start == 1) {
			if ((*num)[start] == (*num)[end]) {
				cache[start][end] = 1;
			}
			else
				cache[start][end] = 0;
		}
		else {
			if ((*num)[start] == (*num)[end]) {
				cache[start][end] = isPel(num, start + 1, end - 1);
			}
			else {
				cache[start][end] = 0;
				return 0;
			}
		}
	}
	return cache[start][end];
}
/*comment*/
//+1���� -1���� üũ�ؼ� Up, Down Ȯ���Ͽ� Ǯ������� �ð��ʰ�
//sorted �������� üũ�ؼ� Ǯ������� ����ε� ���� �ȳ���
//���ƾ���
//������ ���� �̿��ؼ� �׳� ������ ��
//�ð��ʰ�
//�׳� ������ ���ߴµ� �ð��ʰ�
//DP + memoization ������� �ٲ������
//�ð��ʰ�
//end - start == 1 �϶� ���� �ٸ���� case�з��� ��������