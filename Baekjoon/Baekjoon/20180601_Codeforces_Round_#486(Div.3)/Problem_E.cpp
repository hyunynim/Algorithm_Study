#include<cstdio>
#include<vector>
#include<iostream>
#include<deque>
typedef long long ll;

using namespace std;
int main() {
	ll n, tmp;
	deque<int> num;
	int cnt[10] = { 0 };
	cin >> n;
	while (tmp > 0) {
		cnt[tmp % 10]++;
		num.push_front(tmp % 10);
		tmp /= 10;
	}
	if ((cnt[0] >= 2)
		|| (cnt[0] > 0 && cnt[5] > 0)
		|| (cnt[2] > 0 && cnt[5] > 0)
		|| (cnt[7] > 0 && cnt[5] > 0))
	{
		int res = 0;
		vector<int> passing;
		int pos[2] = { 0 };
		for (int i = num.size() - 1; i >= 0; --i) {
			if (num[i] == 0 || num[i] == 5)
				break;
			++pos[0];
		}
		for (int i = num.size() - 1; i >= 0; --i) {
			if (num[i] == 7 || num[i] == 2)
				break;
			++pos[0];
		}

	}
	else {
		printf("-1");
	}
}