#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int n, tmp;
	scanf("%d", &n);
	vector<int> seq;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	int m;
	scanf("%d", &m);

	sort(seq.begin(), seq.end());
	for (int i = 0; i < m; ++i) {
		scanf("%d", &tmp);
		printf("%d ", count(seq.begin(), seq.end(), tmp));
	}
	
}

/*comment*/
//�ð��ʰ�
//����Ž�� �� �յڷ� ���Ƹ��°� ���