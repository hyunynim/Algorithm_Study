#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<string.h>
#define INF -987654321
using namespace std;

vector<pair<int, int>> pay;
int n, tmp1, tmp2;
int cache[26];
int maxPay = 0;

int GetPay(int curPay, int curDay) {
	if (curDay > n)
		return INF;
	if (curDay == n)
		return curPay;
	else {
		int res = curPay;
		for (int i = curDay; i < n; ++i) {
			res = max(res, GetPay(curPay + pay[i].second, i + pay[i].first));
		}
		return res;
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &tmp1, &tmp2);
		pay.push_back(make_pair(tmp1, tmp2));
	}
	printf("%d", GetPay(0,0));
}

/*comment*/
//�� �̰� �� ����ó�� �ȵǳ�
//���Ϳ� ��¥�� �޾ƿͼ� ��¥�� ��Ȯ�� ������ ��쿡�� Sum����ϰ� max ���
//Ʋ�� �� �̰� ��Ʋ���� ���ذ� �ȵǳ�
//���ƾ���
//�� �¾Ҵٵ����߱�߱�߱�