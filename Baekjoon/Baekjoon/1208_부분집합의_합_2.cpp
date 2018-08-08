#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<utility>
using namespace std;
long long a, b;
int n, s, tmp;
vector<int> seq[2];
priority_queue<int> res2;
priority_queue<int, vector<int>, greater<int>> res1;
void calc(int sub, int ind) {
	int sum = 0;
	for (int i = 0; i < n/2 + ind; ++i) {
		if (sub & (1 << i))
			sum += seq[ind][i];
	}
	if (ind)
		res2.push(sum);
	else
		res1.push(sum);

}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (i < n / 2) seq[0].push_back(tmp);
		else seq[1].push_back(tmp);
	}
		a = (1 << (n / 2)) - 1; b = (1 << (n - n / 2)) - 1;
		while (a) 
			calc(a--, 0);
		calc(0, 0);
		while (b)
			calc(b--, 1);
		calc(0, 1);
		long long ans = 0, cur1, cur2, cnt1, cnt2;
		bool popInd[2] = { 1, 1 };

		while (res1.size() || res2.size()) {
			if (res1.size() && popInd[0]) {
				cur1 = res1.top(); res1.pop(); 
				cnt1 = 1;
				while (res1.size() && cur1 == res1.top()) {
					++cnt1;
					res1.pop();
				}
			}
			if (res2.size() && popInd[1]) {
				cur2 = res2.top(); res2.pop(); 
				cnt2 = 1;
				while (res2.size() && cur2 == res2.top()) {
					++cnt2;
					res2.pop();
				}
			}
			
			if (cur1 + cur2 == s) {
				ans += cnt1 * cnt2;
				popInd[0] = popInd[1] = 1;
			}
			else if (cur1 + cur2 < s) {
				if (res1.empty())
					break;
				popInd[0] = 1;
				popInd[1] = 0;
			}
			else {
				if (res2.empty())
					break;
				popInd[0] = 0;
				popInd[1] = 1;
			}
			
		}
		printf("%lld", s ? ans : ans - 1);
}