#include<cstdio>
#include<vector>

using namespace std;
int n, m;
vector<int> seq;
int minsub = 2100000000;
int minSum = 0;


int main() {
	scanf("%d %d", &n, &m);
	int tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}

	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (m >= (seq[i] + seq[j] + seq[k]) && m - (seq[i] + seq[j] + seq[k]) < minsub) {
					minsub = m - (seq[i] + seq[j] + seq[k]);
					minSum = (seq[i] + seq[j] + seq[k]);
				}
			}
		}
	}
	printf("%d", minSum);
}
/*comment*/
//���� M�� ���� �ʴ°��� ������� ����
//��Ʋ��... ��Ʋ����
//minsub ��� �߸���