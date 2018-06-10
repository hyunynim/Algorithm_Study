#include<cstdio>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<string, int>> sell;
	char msg[12345];
	for (int i = 0; i < n; ++i) {
		bool exist = 0;
		scanf("%s", msg);
		string tmp = msg;
		for (int i = 0; i < sell.size(); ++i) {
			if (sell[i].first == tmp) {
				sell[i].second++;
				exist = 1;
				break;
			}
		}
		if (exist);
		else
			sell.push_back(make_pair(tmp, 1));
	}
	vector<string> res;
	int maxCnt = 0;
	for (int i = 0; i < sell.size(); ++i) {
		if (sell[i].second > maxCnt) {
			res.clear();
			maxCnt = sell[i].second;
			res.push_back(sell[i].first);
		}
		else if (sell[i].second == maxCnt)
			res.push_back(sell[i].first);
	}
	sort(res.begin(), res.end());
	printf("%s", res[0].c_str());
}