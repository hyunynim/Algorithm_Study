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
//아 이거 참 생각처럼 안되네
//벡터에 날짜만 받아와서 날짜가 정확히 떨어질 경우에만 Sum계산하고 max 계산
//틀림 하 이거 왜틀리나 이해가 안되네
//갈아엎음
//하 맞았다따끄뜨까뜨까뜨까