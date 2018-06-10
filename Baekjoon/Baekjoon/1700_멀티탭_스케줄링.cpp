#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional>
#include<queue>
using namespace std;

int main() {
	int n, k;
	int cnt[101] = { 0 };
	int tmp;
	vector<int> seq;
	scanf("%d %d", &n, &k);
	if (n == 1) {
		printf("%d", k);
		return 0;
	}

	for (int i = 0; i < k; ++i) {
		scanf("%d", &tmp);
		cnt[tmp]++;
		seq.push_back(tmp);
	}
	vector<pair<int, int>> seqCnt;
	for (int i = 0; i < seq.size(); ++i) {
		seqCnt.push_back(make_pair(cnt[i], seq[i]));
	}

	int res = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> plug;
	long long isPlug[3] = { 0 };
	for (int i = 0; i < k; ++i) {
		if (isPlug[seq[i] / 50] & (1 << seq[i] % 50));
		else {
			if (plug.size() < n) {
				if (isPlug[seq[i] / 50] & (1 << seq[i] % 50))
					continue;
				isPlug[seq[i] / 50] |= (1 << seq[i] % 50);
				plug.push(seqCnt[i]);

			}
			else {
				tmp = plug.top().second;
				isPlug[tmp / 50] &= (~(1 << tmp % 50));
				plug.pop();
				res++;
			}
		}
	}
	printf("%d", res);
}

/*comment*/
//��Ÿ�ӿ��� -> 1~100���� �����Ƿ� �迭 3ĭ�ʿ�
//Ʋ��
//�ϳ� �� ������ �ڿ� � ���Ҵ��� ������ ��Ʒ��� �ҰͰ���
//���� ���� �����δ� �� �ϱ� ����� ���ƾ��� ����