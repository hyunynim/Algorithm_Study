#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	int seqMax = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		if (seq[i] > seqMax) {
			seqMax = seq[i];
			maxIndex = i;
		}
	}
	int res = 0;
	int curMax = -1;
	for (int i = 0; i < seq.size(); ++i) {
		if (seq[i] > curMax) {
			++res;
			curMax = seq[i];
		}
	}
	printf("%d\n", res);
	res = 0;
	curMax = -1;
	for (int i = seq.size() - 1; i >= 0; --i) {
		if (seq[i] > curMax) {
			++res;
			curMax = seq[i];
		}
	}
	printf("%d", res);
}

/*comment*/
//ó���� �ִ񰪱����� Ž���ϰ� ������ �ִ��� 2�� �̻��� ��� ����� ���� ����