#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int l, n;
	scanf("%d", &l);
	vector<int> seq;
	for (int i = 0; i < l; ++i) {
		scanf("%d", &n);
		seq.push_back(n);
	}
	scanf("%d", &n);
	sort(seq.begin(), seq.end());

	if (find(seq.begin(), seq.end(), n) != seq.end()) {
		printf("0");
		return 0;
	}
	else {
		int i = 1;
		int res = 0;
		if (n < seq[0]) {
			for (int j = 1; j <= n; ++j) {
				for (int k = n; k < seq[0]; ++k) {
					++res;
				}
			}
		}
		else {
			while (!(seq[i - 1] < n && n < seq[i]))
				++i;
			for (int j = seq[i - 1] + 1; j <= n; ++j) {
				for (int k = n; k < seq[i]; ++k) {
					++res;
				}
			}
		}
		printf("%d", res  -1 );
		//printf("%d", n - seq[i - 1] + seq[i] - n - 2 + (n - seq[i - 1] - 1)*(seq[i] - n - 1));
	}
}
//���ٷ� ����ϰ� Ǯ��� ������ ����
//�׳� �����ϰ� Ǯ��ôµ� ���� n < seq[0] �ΰ�� ��� ����