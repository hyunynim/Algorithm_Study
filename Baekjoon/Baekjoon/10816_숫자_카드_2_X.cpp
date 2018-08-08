#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> seq;
vector<pair<int, int>> uSeq;

int bSearch(int left, int right, int dat) {
	if (left > right)
		return -1;
	int mid = (left + right) / 2;
	if (uSeq[mid].first > dat)
		return bSearch(left, mid - 1, dat);
	else if (uSeq[mid].first < dat)
		return bSearch(mid + 1, right, dat);
	else if (uSeq[mid].first == dat)
		return mid;
}

int main() {
	int n, tmp;
	scanf("%d", &n);
	
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
			uSeq.push_back({ tmp, cnt });
			cnt = 1;
			tmp = seq[i];
		}
	}
	uSeq.push_back({ tmp, cnt });
	int vSize = uSeq.size() - 1;
	int index;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &n);
		index = bSearch(0, vSize, n);
		if (index != -1)
			printf("%d ", uSeq[index].second);
		else
			printf("0 ");
		
	}
}

/*comment*/
//�ð��ʰ�
//����Ž�� �� �յڷ� ���Ƹ��°� ���
//����Ž�� �� ���� ���Ƹ��� �ð��ʰ�
//ó�� �Է¹����� ���� �� ���� ���� ����
//�ð��ʰ�
//ok