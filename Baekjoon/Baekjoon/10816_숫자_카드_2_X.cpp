#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int n, tmp;
	scanf("%d", &n);
	vector<int> seq;
	vector<int> uSeq, uSeqCnt;
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	int m;
	scanf("%d", &m);

	sort(seq.begin(), seq.end());
	tmp = seq.front();
	int cnt = 1;
	for (int i = 1; i < seq.size(); ++i) {
		if(seq[i] == tmp){
			cnt++;
		}
		else {
			uSeq.push_back(tmp);
			uSeqCnt.push_back(cnt);
			cnt = 1;
			tmp = seq[i];
		}
	}
	if (tmp != uSeq.back()) {
		uSeq.push_back(tmp);
		uSeqCnt.push_back(cnt);
	}

	vector<int>::iterator vPtr;
	for (int i = 0; i < m; ++i) {
		int cnt = 0;
		scanf("%d", &tmp);
		vPtr = find(uSeq.begin(), uSeq.end(), tmp);
		if (vPtr == uSeq.end())
			printf("0 ");
		else {
			cnt = vPtr - uSeq.begin();
			printf("%d ", uSeqCnt[cnt]);
		}
	}
	
}

/*comment*/
//�ð��ʰ�
//����Ž�� �� �յڷ� ���Ƹ��°� ���
//����Ž�� �� ���� ���Ƹ��� �ð��ʰ�
//ó�� �Է¹����� ���� �� ���� ���� ����
//�ð��ʰ�