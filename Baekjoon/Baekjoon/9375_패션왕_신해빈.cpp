#include<cstdio>
#include<string>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<pair<string, string>> seq;
vector<int> res;
ll sumRes = 0;
int n;

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			char msg[2][30];
			string tmp1, tmp2;
			scanf("%s%s", msg[0], msg[1]);

			tmp1.assign(msg[0]);
			tmp2.assign(msg[1]);

			seq.push_back(make_pair(tmp2, tmp1));
		}
		if (n == 1) {
			printf("1\n");
			res.clear();
			seq.clear();
			continue;
		}
		sort(seq.begin(), seq.end());
		int cnt = 1;
		for (int j = 1; j < seq.size(); ++j) {
			if (seq[j].first == seq[j - 1].first)
				++cnt;
			else {
				res.push_back(cnt);
				cnt = 1;
			}
			if (j == seq.size() - 1)
				res.push_back(cnt);
		}
		sumRes = 1;
		for (int j = 0; j < res.size(); ++j) {
			sumRes *= (res[j] + 1);
		}
		printf("%lld\n", sumRes-1);
		res.clear();
		seq.clear();
	}
}

/*commnet*/
//시간초과
//계산을 조금 더 빠르게 할 수 있는 방법?
//옷을 입지 않는 경우를 하나의 경우로 추가해서 전부 곱셈으로 구함
//거기서 전부 옷을 입지 않는 케이스를 선택했을 때 하나를 빼주면 되는 듯
//n==1인 경우 처리 안해줌